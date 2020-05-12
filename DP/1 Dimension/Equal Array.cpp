#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 10000000005
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
		ll arr[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			arr[i]+=arr[i-1];
			// cout<<arr[i]<<" ";
		}

		ll ans=MAX;
		for(int i=1;i<n;i++)
		{
			ll x=arr[n]-arr[i]-arr[i];
			if(x>=0)
				ans=min(ans,x);
		}
		if(ans==MAX)
			ans=-1;
		cout<<ans<<'\n';
	}
	return 0;
}