#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 10015
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
int n,time_in[MAX],time_out[MAX],timer,dp[MAX][20],l;
std::vector<int> adj[MAX];
int status[MAX];

void dfs(int u,int par){
	status[u]=visited;
	time_in[u]=++timer;
	dp[u][0]=par;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial)
			dfs(v,u);
	}
	time_out[u]=++timer;
}

bool is_ancestor(int u,int v)
{
	if(time_in[u]<=time_in[v]&&time_out[u]>=time_out[v])
		return true;
	return false;
}

int lcs(int u,int v)
{
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;
	for(int i=l;i>=0;i--){
		if(!is_ancestor(dp[u][i],v))
			u=dp[u][i];
	}
	return dp[u][0];
}
int main()
{
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		for(int i=0;i<MAX;i++)
			adj[i].clear(),status[i]=intial;
		timer=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int m;
			cin>>m;
			for(int j=0;j<m;j++){
				int v;
				cin>>v;
				adj[i].pb(v);
				adj[v].pb(i);
			}
		}
		dfs(1,1);

		l=ceil(log2(n));
		for(int j=1;j<=l;j++){
			for(int i=1;i<=n;i++)
				dp[i][j]=dp[dp[i][j-1]][j-1];
		}
		cout<<"Case "<<test<<":\n";
		int q;
		cin>>q;
		while(q--){
			int u,v;
			cin>>u>>v;
			int ans=lcs(u,v);
			cout<<ans<<endl;
		}
	}
	return 0;
}