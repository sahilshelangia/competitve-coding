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
std::vector<int>adj[MAX];
int status[MAX];
bool leaf[MAX];
ll dp[MAX][22];
int n,m;

void dfs(int u,int par){
	status[u]=visited;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[u][__gcd(i,j)]+=dp[par][j];
		}
	}
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial){
			dfs(v,u);
			leaf[u]=false;
		}
	}
}
int main()
{
	fast;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(dp,0,sizeof(dp));
	memset(status,intial,sizeof(status));
	memset(leaf,true,sizeof(leaf));	
	for(int i=0;i<22;i++)
		dp[1][i]=1;
	dfs(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){	
		// if(leaf[i])	
		cout<<i<<" =\n";
		for(int j=1;j<=m;j++)
		cout<<j<<": "<<dp[i][j]<<endl;
	}

	return 0;
}