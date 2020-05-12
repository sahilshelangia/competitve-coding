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
	int n;
	cin>>n;
	int choc[n+2][n+1]={0};
	for(int i=n;i>=1;i--)	
	{
		for(int j=1;j<=n;j++)
			cin>>choc[i][j];
	}

	ll dp[n+2][n+2]={0},ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=choc[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
			ans=max(dp[i][j],ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}