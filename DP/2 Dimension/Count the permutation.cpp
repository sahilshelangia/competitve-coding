#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+9;
#define MAX 105
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
	ll dp[MAX][MAX];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(j==0)
				dp[i][j]=1;
			else{
				if(i>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=(dp[i-1][j]+dp[i][j-i])%MOD;
			}
		}
	}
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	int t;
	cin>>t;
	while(t--){
		int a,s;
		cin>>a>>s;
		int x=s-1;
		if(x==0){
			cout<<dp[MAX-1][a]<<endl;
		}
		else{
			ll sum=dp[x][a];
			for(int i=a;i>=1;){
				sum+=dp[x][i];
				i=i-s;
			}
			sum=sum%MOD;

			ll ans=(dp[MAX-1][a]-sum+MOD)%MOD;
			cout<<ans<<endl;
		}
	}
	return 0;
}