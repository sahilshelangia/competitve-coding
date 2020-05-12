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
ll dp[MAX][4];

ll count(ll n,ll occur)
{
	if(n<0||occur>=3)
		return 0;
	if(n==1&&occur<3)
		return 1;
	if(dp[n][occur]!=-1)
		return dp[n][occur];
	dp[n][occur]=count(n-1,occur+1)+count(n-1,0);
	return dp[n][occur];
}
int main()
{
	for(int i=0;i<MAX;i++)
		for(int j=0;j<4;j++)
			dp[i][j]=-1;

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=count(n+1,0);
		cout<<ans<<endl;
	}
	return 0;
}