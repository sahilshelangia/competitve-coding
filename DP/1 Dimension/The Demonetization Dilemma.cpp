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
	int t;
	cin>>t;
	while(t--)
	{
		int a,n;
		cin>>a>>n;
		int arr[n+1];
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		ll dp[n+1][a+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=a;j++)
			{
				if(j==0)
					dp[i][j]=0;
				else
					dp[i][j]=MOD;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=a;j++)
			{
				if(arr[i]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=min(dp[i-1][j],1+dp[i][j-arr[i]]);
			}
		}
		// for(int i=0;i<=n;i++)
		// {
		// 	for(int j=0;j<=a;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }
		if(dp[n][a]>=MOD)
		{
			cout<<"No solution\n";
			continue;
		}
		cout<<dp[n][a]<<'\n';
	}
	return 0;
}