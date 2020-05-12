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
struct dimension
{
	ll l,b,h;
};

bool cmp(dimension d1,dimension d2)
{
	return d1.l*d1.b>d2.l*d2.b;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		dimension arr[7*n];
		for(int i=0;i<6*n;i+=6)
		{
			cin>>arr[i].l>>arr[i].b>>arr[i].h;
			arr[i+1].l=arr[i].l;
			arr[i+1].b=arr[i].h;
			arr[i+1].h=arr[i].b;

			arr[i+2].l=arr[i].b;
			arr[i+2].b=arr[i].l;
			arr[i+2].h=arr[i].h;

			arr[i+3].l=arr[i].b;
			arr[i+3].b=arr[i].h;
			arr[i+3].h=arr[i].l;

			arr[i+4].l=arr[i].h;
			arr[i+4].b=arr[i].b;
			arr[i+4].h=arr[i].l;

			arr[i+5].l=arr[i].h;
			arr[i+5].b=arr[i].l;
			arr[i+5].h=arr[i].b;
		}
		sort(arr,arr+6*n,cmp);

		ll ans[6*n],final=0;
		for(int i=0;i<6*n;i++)
			ans[i]=arr[i].h;
		for(int i=0;i<6*n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if((arr[j].l>arr[i].l)&&(arr[j].b>arr[i].b))
					ans[i]=max(ans[i],ans[j]+arr[i].h);
			}
			final=max(ans[i],final);
		}
		cout<<final<<endl;
	}
	return 0;
}