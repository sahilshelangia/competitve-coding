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
	int x;
	cin>>x;
	int n;
	cin>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];

	ll dp[n+1][x+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			if(a[i]<=j)
			{
				dp[i][j]=max(dp[i][j-a[i]]+b[i],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}	
		}
	}
	ll ans=0;
	for(int i=0;i<=x;i++)
		ans=max(dp[n][i],ans);
	cout<<ans<<endl;
	return 0;
}