#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 50005
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
std::vector< pair<int,int> > adj[MAX];
ll n,dp[MAX][20],l,status[MAX]={0},time_in[MAX],time_out[MAX],timer=0,dis[MAX]={0};

void dfs(int u){
	status[u]=visited;
	time_in[u]=++timer;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		if(status[v]==intial){
			dis[v]=dis[u]+adj[u][i].second;
			dp[v][0]=u;
			dfs(v);
		}
	}
	time_out[u]=++timer;
}

bool is_ancestor(int u,int v){
	return time_in[u]<=time_in[v]&&time_out[u]>=time_out[v];
}

int lcs(int u,int v){
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
	fast;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	l=ceil(log2(n));
	dp[0][0]=0;
	dis[0]=0;
	dfs(0);
	// fill dp table
	for(int i=1;i<=l;i++){
		for(int j=0;j<n;j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	}

	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=dis[u]+dis[v]-2*dis[lcs(u,v)];
		cout<<ans<<endl;
	}


	return 0;
}