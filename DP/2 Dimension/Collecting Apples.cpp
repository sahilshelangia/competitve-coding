#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1010
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
int milk[MAX],apple[MAX],dp[MAX][MAX];;
int n;
ll p;


int max_apple(int farm,int energy){
	if(energy<0||farm>n)
		return 0;
	else{
		if(dp[farm][energy]==-1){
			int ans=max_apple(farm+1,energy-1)+apple[farm];
			ans=max(ans,max_apple(farm+1,min(n,energy-1+milk[farm])));
			dp[farm][energy]=ans;	
		}
		return dp[farm][energy];		
	}
}
int main()
{
	// fast;
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		cin>>n>>p;
		for(int i=1;i<=n;i++)
			cin>>milk[i];
		for(int i=1;i<=n;i++)
			cin>>apple[i];
		if(p>=n)
		{
			ll ans=0;
			for(int i=1;i<=n;i++)
				ans+=apple[i];
			cout<<ans<<endl;
			continue;
		}
		int ans=max_apple(1,p-1);
		cout<<ans<<'\n';
	}
	return 0;
}