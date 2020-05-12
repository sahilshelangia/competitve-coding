#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 5005
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
int n,arr[MAX],cumm[MAX],len;
vector<ll>p;

ll dp[MAX];
ll findmax(ll n)
{
	if(n<=1)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	ll tmp=findmax(n-1);
	for(int i=0;i<len;i++)
	{
		if(p[i]<=n)
			tmp=max(tmp,findmax(n-p[i]-1)+cumm[n]-cumm[n-p[i]]);
		else
			break;
	}
	dp[n]=tmp;
	return dp[n];
}
int main()
{
	bool prime[MAX];
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=false;
		}
	}
	for(int i=2;i<MAX;i++)
		if(prime[i])
			p.pb(i);
	len=p.size();


	memset(cumm,0,sizeof(cumm));
	cin>>n;
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		cumm[i]=arr[i]+cumm[i-1];
	}
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	ll ans=findmax(n);
	cout<<ans<<endl;
	return 0;
}