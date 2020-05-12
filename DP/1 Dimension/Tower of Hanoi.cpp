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
struct dim
{
	ll ht,r;
};

bool cmp1(dim a,dim b)
{
	if(a.r>b.r)
		return true;
	else if(a.r==b.r)
	{
		if(a.ht>=b.ht)
			return true;
		else
			return false;
	}
	else 
		return false;
}

bool cmp2(dim a,dim b)
{
	if(a.ht>b.ht)
		return true;
	else if(a.ht==b.ht)
	{
		if(a.r>=b.r)
			return true;
		else
			return false;
	}
	else 
		return false;
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		ll n,ans=0;
		cin>>n;
		dim arr[n];
		ll lis[n];
		for(int i=0;i<n;i++)
			cin>>arr[i].r>>arr[i].ht;
		sort(arr,arr+n,cmp1);
		for(int i=0;i<n;i++)
			lis[i]=arr[i].ht;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if((arr[j].r>arr[i].r)&&(arr[j].ht>arr[i].ht))
					lis[i]=max(lis[i],lis[j]+arr[i].ht);
			}
			ans=max(ans,lis[i]);
		}

		sort(arr,arr+n,cmp2);
		for(int i=0;i<n;i++)
			lis[i]=arr[i].ht;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if((arr[j].r>arr[i].r)&&(arr[j].ht>arr[i].ht))
					lis[i]=max(lis[i],arr[i].ht+lis[j]);
			}
			ans=max(ans,lis[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}