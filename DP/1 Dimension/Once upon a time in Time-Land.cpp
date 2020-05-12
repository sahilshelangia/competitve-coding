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

ll rever(ll x)
{
	if(x<=9)
		return x;
	ll ans=0;
	while(x)
	{
		ans=ans*10+x%10;
		x=x/10;
	}
	return ans;
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		a=rever(a);
		b=rever(b);
		ll ans=a+b;
		ans=rever(a+b);
		cout<<ans<<endl;
	}
	return 0;
}