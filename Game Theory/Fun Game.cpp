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

struct game
{
	ll a,b,res;
};
bool cmp(game g1,game g2)
{
	return g1.res>g2.res;
}

int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		game g[n];
		for(int i=0;i<n;i++)
			cin>>g[i].a;
		for(int i=0;i<n;i++)
			cin>>g[i].b;
		for(int i=0;i<n;i++)
			g[i].res=g[i].a+g[i].b;
		sort(g,g+n,cmp);

		// for(int i=0;i<n;i++)
		// 	cout<<
		ll sca=0,scb=0;
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
				sca+=g[i].a;
			else
				scb+=g[i].b;
		}
		if(sca>scb)
			cout<<"First"<<endl;
		else if(sca==scb)
			cout<<"Tie"<<endl;
		else
			cout<<"Second"<<endl;
	}
	return 0;
}