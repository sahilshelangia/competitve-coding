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
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
ll n,score[MAX],dp[MAX];

ll sum(ll n)
{
	if(n<0)
		return 0;
	if(dp[n]==-1)
		dp[n]=max(score[n]+sum(n-2),sum(n-1));
	return dp[n];
}
int main()
{
	fast;
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>score[i];
		memset(dp,-1,sizeof(dp));
		ll ans=sum(n-1);
		cout<<"Case "<<test<<": "<<ans<<endl;
	}
	return 0;
}