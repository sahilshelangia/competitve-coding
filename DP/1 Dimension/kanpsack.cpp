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
		ll wt[n+1],val[n+1],W;
		cin>>W;
		for(int i=1;i<=n;i++)
			cin>>val[i];
		for(int i=1;i<=n;i++)
			cin>>wt[i];
		ll dp[n+1][W+1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=W;j++)
				dp[i][j]=0;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=W;j++)
			{
				if(wt[i]<=j)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+val[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		ll ans=0;
		for(int i=0;i<=W;i++)
		{
			if(dp[n][i])
				ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
		// for(int i=0;i<=n;i++)
		// {
		// 	for(int j=0;j<=W;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }
	}
	return 0;
}