#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000205
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
std::vector<int> v;
int nsp[MAX],ngp[MAX];
ll costs(ll x,ll y)
{
	ll ans=MAX;
	if(x<y)
		ans=min(ans,nsp[y]-x);
	else if(y<=x)
		ans=min(ans,ngp[x]-y);
	return ans;
}
int main()
{
	fast;
	int np[MAX];
	bool prime[MAX];
	memset(prime,true,sizeof(prime));
	for(int i=2;i<MAX;i++)
	{
		if(prime[i])
		{
			v.pb(i);
			for(int j=2*i;j<MAX;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	int sz=v.size(),prev=v[sz-1];
	prime[1]=false;
	for(int i=MAX-1;i>=0;i--)
	{
		ngp[i]=prev;
		if(prime[i])
			prev=i;
		np[i]=prev;
	}
	prev=2;
	for(int i=2;i<MAX;i++)
	{
		nsp[i]=prev;
		if(prime[i])
			prev=i;
	}

	int n;
	cin>>n;
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
 
	int transform_cost[n][n]={0};
 
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int xa=np[arr[i]],xb=np[arr[j]];
			int convert=costs(xa,xb);
			convert+=xa-arr[i]+xb-arr[j]+1;
			transform_cost[i][j]=convert;
		}
	}


	int dp[n][n]={0};
	for(int l=2;l<=n;l+=2)
	{
		for(int i=0;i<=n-l;i++)
		{
			int left=i,right=i+l-1;
			if(l==2)
				dp[left][right]=transform_cost[left][right];
			else
			{
				dp[left][right]=INT_MAX;
				for(int j=left+1;j<=right;j+=2)
				{
					if(j+1<=right)
						dp[left][right]=min(dp[left][right],transform_cost[left][j]+dp[left+1][j-1]+dp[j+1][right]);
					else
						dp[left][right]=min(dp[left][right],transform_cost[left][j]+dp[left+1][j-1]);
				}
			}
		}
	}
	cout<<dp[0][n-1]<<'\n';
 
	return 0;
}