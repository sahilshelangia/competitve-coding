#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 35
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
	ll dp[MAX][MAX];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(j==0)
				dp[i][j]=1;
			else
			{
				if(i>=j)
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				else
					dp[i][j]=0;
			}
		}
	}
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=dp[2*n][n]/(n+1);
		cout<<ans<<endl;
	}
	return 0;
}