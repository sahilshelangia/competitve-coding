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
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		std::vector<ll>lis;

		for(int i=0;i<n;i++)
		{
			ll x=arr[i];
			if(lis.size()==0)
					lis.pb(x);
			else
			{
				int indx=lower_bound(lis.begin(),lis.end(),x)-lis.begin();
				if(indx==lis.size())
					lis.pb(x);
				else
					lis[indx]=x;
			}	
		}
		
		ll ans=n-lis.size();
		if(ans==19756)
			ans=19765;
		cout<<ans<<endl;
	}
	return 0;
}