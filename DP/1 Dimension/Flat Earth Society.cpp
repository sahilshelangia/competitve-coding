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
ll n,l,r,arr[MAX],dplr[MAX],dprl[MAX];


ll callr(ll x)
{
	if(x>n)
		return 0;
	if(dplr[x]!=-1)
		return dplr[x];
	else
	{
		ll xx=upper_bound(arr,arr+n+1,arr[x])-lower_bound(arr,arr+n+1,arr[x]);
		ll yy=upper_bound(arr,arr+n+1,arr[x]+r)-arr;
		dplr[x]=max(callr(x+1),xx*arr[x]+callr(yy));
	}
	return dplr[x];
}

ll calrl(ll n)
{
	if(n<=0)
		return 0;
	if(dprl[n]!=-1)
		return dprl[n];
	else
	{
		ll x=upper_bound(arr,arr+n+1,arr[n])-lower_bound(arr,arr+n+1,arr[n]);
		ll y=upper_bound(arr,arr+n+1,arr[n]-l-1)-arr-1;
		dprl[n]=max(calrl(n-1),x*arr[n]+calrl(y));
	}
	return dprl[n];
}

int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		arr[0]=0;
		sort(arr,arr+n+1);
		memset(dprl,-1,sizeof(dprl));
		memset(dplr,-1,sizeof(dplr));
		ll ans=calrl(n);
		ans=max(ans,callr(1));
		cout<<ans<<'\n';
	}
	return 0;
}