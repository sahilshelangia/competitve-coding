#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+9;
#define MAX 10000005
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
	ll ans[MAX]={0};
	ans[1]=1;
	for(ll i=3;i<MAX;i+=2)
		ans[i]=(ans[i-2]+4*i*i-6*(i-1))%MOD;
	for(ll i=2;i<MAX;i+=2)
		ans[i]=(ans[i-2]+4*i*i-6*(i-1))%MOD;
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}