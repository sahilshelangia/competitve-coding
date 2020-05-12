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
	bool prime[MAX],check[MAX];
	memset(prime,true,sizeof(prime));
	memset(check,false,sizeof(check));
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i]==true)
		{
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=false;
		}
	}

	vector<ll>primlatic;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i])
		{
			check[i]=true;
			primlatic.pb(i);
			if(i<=7)
			{
				ll x=pow(i,i);
				if(x<MAX)
				{
					primlatic.pb(x);
					check[x]=true;
				}
			}
		}
	}


	ll ans[MAX]={0},len=primlatic.size();
	sort(primlatic.begin(),primlatic.end());

	for(int i=0;i<MAX;i++)
	{
		if(check[i])
			ans[i]=1;
		if(ans[i]==0)
			continue;
		for(int j=0;j<len;j++)
		{
			ll x=i+primlatic[j];
			if(x<MAX)
			{
				if(ans[x]==0)
					ans[x]=ans[i]+1;
				else
					ans[x]=min(ans[x],ans[i]+1);
			}
		}
	}
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