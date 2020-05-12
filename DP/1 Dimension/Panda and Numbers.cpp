#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000005
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
set<ll>s;
ll dp[MAX];

ll check(ll n)
{
	if(n<=0)
		return 0;
	if(s.find(n)!=s.end())
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	ll tmp=n;
	while(tmp)
	{
		ll x=(tmp%10)*(tmp%10);
		tmp=tmp/10;
		if(x!=0)
			dp[n]=max(dp[n],check(n-x));

	}
	return dp[n];
}
ll power(ll x,ll n)
{
	ll res=1;
	while(n)
	{
		if(n%2==1)
			res=res*x;
		n=n/2;
		x=x*x;
	}
	return res;
}

int main()
{
	
	for(ll i=1;1;i++)
	{
		ll x=power(i,i);
		if(x<MAX)
			s.insert(x);
		else
			break;
	}
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=check(n);
		if(ans==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	
	return 0;
}