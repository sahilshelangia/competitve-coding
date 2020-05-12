#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
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
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll cost[n+1][3]={0};
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>cost[i][j];

		ll dp[n+1][2]={0};

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(j==0)
					dp[i][j]=cost[i][j]+min(dp[i-1][j+1],dp[i-1][j+2]);
				else if(j==1)
					dp[i][j]=cost[i][j]+min(dp[i-1][j-1],dp[i-1][j+1]);
				else
					dp[i][j]=cost[i][j]+min(dp[i-1][j-1],dp[i-1][j-2]);
			}
		}

		ll ans=min3(dp[n][0],dp[n][1],dp[n][2]);
		cout<<ans<<endl;
	}
	return 0;
}