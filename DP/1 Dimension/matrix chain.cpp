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
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		ll mat[n-1][2];
		for(int i=0;i<n-1;i++)
		{
			mat[i][0]=arr[i];
			mat[i][1]=arr[i+1];
		}
		ll dp[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				dp[i][j]=0;
		}
		for(int len=2;len<=n-1;len++)
		{
			for(int i=0;i+len-1<n;i++)
			{
				ll left=i,right=i+len-1,ans=MOD;
				for(int k=left;k<right;k++)
				{
					ans=min(ans,dp[left][k]+dp[k+1][right]+mat[left][0]*mat[k][1]*mat[right][1]);
				}
				dp[left][right]=ans;
			}
		}
		// for(int i=0;i<n-1;i++)
		// {
		// 	for(int j=0;j<n-1;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }
		cout<<dp[0][n-2]<<endl;
	}
	return 0;
}
