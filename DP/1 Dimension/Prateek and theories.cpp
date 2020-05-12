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
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<ll,ll>m;
		for(int i=0;i<n;i++)
		{
			ll l,r;
			cin>>l>>r;
			m[l]++;
			m[r]--;
		}
		map<ll,ll>::iterator it;
		ll ans=0,sum=0;
		for(it=m.begin();it!=m.end();it++)
		{
			sum=sum+it->second;
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}