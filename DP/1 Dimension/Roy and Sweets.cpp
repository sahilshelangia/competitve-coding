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
int main()
{
	int n;
	cin>>n;
	ll s[MAX]={0},q[MAX]={0};
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		s[a]+=b;
	}
	for(int i=MAX-2;i>=0;i--)
		s[i]=max(s[i],s[i+1]);
	int g;
	cin>>g;
	ll ans=0;
	while(g--)
	{
		ll m;
		cin>>m;
		ans+=100*(s[m]/m);
	}
	cout<<ans<<endl;
	return 0;
}