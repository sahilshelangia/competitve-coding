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

struct graph
{
	int cost,length,source;
};
int n,m,b;
int dp[505][1005];
std::vector<graph>adj[505];

int cal(int dest,int bud){
	if(bud<0)
		return -2;
	if(dest==1)
		return 0;
	if(dp[dest][bud]==-1){
		for(int i=0;i<adj[dest].size();i++){
			int x=cal(adj[dest][i].source,bud-adj[dest][i].cost);
			int len=adj[dest][i].length;
			if(x!=-2){
				x=x+len;
				if(dp[dest][bud]==-1)
					dp[dest][bud]=x;
				else
					dp[dest][bud]=min(dp[dest][bud],x);
			}
		}
	}
	if(dp[dest][bud]==-1)
		dp[dest][bud]=-2;
	return dp[dest][bud];
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>b;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<505;i++)
			adj[i].clear();
		for(int i=0;i<m;i++){
			int u,v,c,l;
			cin>>u>>v>>c>>l;
			graph g;
			g.cost=c;
			g.length=l;
			g.source=u;
			adj[v].pb(g);
		}

		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=cal(x,y);
			if(ans==-2)
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}