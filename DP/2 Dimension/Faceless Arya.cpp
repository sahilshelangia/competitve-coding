#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 10005
#define eps 1e-9
#define infi 1000000
#define intial 0
#define waiting 1
#define visited 2
#define nill -1
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int main()
{
	// fast;
	int t;
	cin>>t;
	int spf[MAX];
	memset(spf,-1,sizeof(spf));
	for(int i=2;i<MAX;i++){
		if(spf[i]==-1){
			for(int j=i;j<MAX;j+=i){
				if(spf[j]==-1)
					spf[j]=i;
			}
		}
	}
	

	while(t--){
		ll n,m;
		cin>>n>>m;
		ll arr[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];

		if(n==1){
			ll ans=0;
			for(int j=0;j<m;j++)
				ans=max(ans,arr[0][j]);
			cout<<ans<<endl;
			continue;
		}

		ll dp[MAX]={0};
		for(int j=0;j<m;j++){
			ll x=arr[0][j];
			while(x!=1){
				int fac=spf[x];
				while(x%fac==0)
					x=x/fac;
				dp[fac]=max(dp[fac],arr[0][j]);
			}
		}

		for(int i=1;i<n;i++){
			ll curr_dp[MAX]={0};
			for(int j=0;j<m;j++){
				int x=arr[i][j];		
				while(x!=1){
					int fac=spf[x];
					while(x%fac==0)
						x=x/fac;
					if(dp[fac]!=0)
						curr_dp[fac]=max(curr_dp[fac],dp[fac]+arr[i][j]);	
				}				
			}
			
			for(int i=0;i<MAX;i++)
				dp[i]=curr_dp[i];
		}
		ll ans=0;
		for(int i=0;i<MAX;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
	return 0;
}