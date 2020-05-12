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
ll dp[MAX][3];
ll count(int n,int rem)
{
	if(n<0||rem<0)
		return 0;
	if(n==0&&rem>=0)
		return 1;
	if(dp[n][rem]==-1)
		dp[n][rem]=(count(n-1,rem-1)+count(n-1,2))%MOD;
	return dp[n][rem];
}

int main()
{
	fast;
	int m;
	cin>>m;
	memset(dp,-1.,sizeof(dp));
	while(m--)
	{
		int n;
		cin>>n;
		ll ans=count(n,2);
		cout<<ans<<endl;
	}
	return 0;
}