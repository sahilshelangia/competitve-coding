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
		ll dp[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=0;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		for(int len=2;len<n;len++)
		{
			// cout<<len<<":"<<endl<<endl;
			for(int i=0;i<n-len;i++)
			{
				ll ans=MOD;
				int left=i,right=i+len-1;
				// cout<<left<<" "<<right<<endl;
				for(int j=left;j<right;j++)
				{
					// cout<<"-"<<dp[left][j]+dp[j+1][right]+arr[left]*arr[j+1]*arr[right+1]<<endl;
					ans=min(ans,dp[left][j]+dp[j+1][right]+arr[left]*arr[j+1]*arr[right+1]);
				}
				dp[left][right]=ans;
			}
		}
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }

		cout<<dp[0][n-2]<<endl;
	}
	return 0;
}