#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000005
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
std::vector<int>adj[MAX];
int dp[MAX];
void divisor()
{
	for(int i=1;i<MAX;i++)
	{
		for(int j=2*i;j<MAX;j+=i)
			adj[j].pb(i);
	}
}

int mex(set<int>s)
{
	int m=0;
	while(s.find(m)!=s.end())
		m++;
	return m;
}

int grundy(int n)
{
	if(n<=1)
		return 0;
	if(dp[n]==-1)
	{	
		set<int>s;
		for(int i=0;i<adj[n].size();i++)
			s.insert(grundy(adj[n][i]));
		dp[n]=mex(s);
	}
	return dp[n];
}
int main()
{
	fast;
	divisor();
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int x=grundy(m);
		int ans=0;
		for(int i=0;i<n;i++)
			ans=ans^x;
		if(ans)
			cout<<"1"<<endl;
		else
			cout<<"2"<<endl;
	}
	return 0;
}