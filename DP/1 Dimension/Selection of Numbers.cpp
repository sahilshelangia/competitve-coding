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
	ll k,n;
	cin>>k>>n;
	ll arr[n],sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}

	ll window=0,ans=1e18;
	for(int i=0;i<n-k;i++)
		window+=arr[i];
	ans=min(ans,window);
	for(int i=n-k;i<n;i++)
	{
		window+=arr[i];
		window-=arr[i-(n-k)];
		ans=min(ans,window);
	}
	ans=sum-ans;
	cout<<ans<<endl;
	return 0;
}