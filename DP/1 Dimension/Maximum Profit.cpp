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
		int k,n;
		cin>>k>>n;
		int arr[n+1]={0};
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		ll dp[k+1][n+1];
		for(int i=0;i<=k;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=dp[i][j-1];
				for(int kk=1;kk<=j;kk++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][kk]+arr[j]-arr[kk]);
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=n;i++)
			ans=max(ans,dp[k][i]);
		cout<<ans<<endl;
	}
	return 0;
}