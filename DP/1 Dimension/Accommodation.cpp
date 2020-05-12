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
	ll m,n;
	cin>>m>>n;
	ll cap[m+1];
	for(int i=1;i<=m;i++)
		cin>>cap[i];
	ll dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	for(int i=0;i<=m;i++)
		dp[i][0]=1;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(cap[i]>j)
				dp[i][j]=dp[i-1][j]%MOD;
			else
				dp[i][j]=(dp[i-1][j]+dp[i][j-cap[i]])%MOD;
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;

	}
	cout<<dp[m][n]<<endl;

	return 0;
}