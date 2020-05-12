#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 10005
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
ll pp,dp[MAX][12];
ll count(int n,int p)
{
	if(n<1||p<1)
		return 0;
	if(n==1&&p>0)
		return 1;
	if(dp[n][p]!=-1)
		return dp[n][p];
	else
	{
		dp[n][p]=(count(n-1,p-1)%MOD+count(n-1,pp)%MOD)%MOD;
		return dp[n][p];
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		int n;
		cin>>n>>pp;
		ll ans=count(n,pp)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}