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

ll power(ll x,ll n,ll mod)
{
	ll res=1;
	while(n)
	{
		if(n%2==1)
			res=res*x%mod;
		x=x*x%mod;
		n=n/2;
	}
	return res;
}
bool prime(ll x)
{
	int k=100;
	srand(time(0));
	for(int i=0;i<k;i++)
	{
		ll a=1+rand()%x;
		if(a==x)
			a--;
		if(power(a,x-1,x)!=1)
			return false;
	}
	return true;
}
bool check(ll x)
{
	if(prime(x))
		return false;
	else
	{
		ll front=x%(ll)(pow(10,int(log10(x))));
		ll back=x/10;
		bool ans;
		if(check(back)==true||check(front)==true)
			ans=true;
		else
			ans=false;
		ans=!ans;
		return ans;
	}
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		if(!check(x))
			cout<<"Alice"<<endl;
		else
			cout<<"Bob"<<endl;
	}
	return 0;
}