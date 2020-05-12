#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
#define eps 1e-9
#define infi 1000000000
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
std::vector<PII> adj[MAX];
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
	}
	ll dis[n+1];
	for(int i=0;i<=n;i++)
		dis[i]=infi;
	int status[n+1];
	memset(status,intial,sizeof(status));
	multiset<PII>ms;
	dis[1]=0;
	ms.insert(mp(0,1));
	while(!ms.empty()){
		ll u=(*ms.begin()).second;
		ms.erase(ms.begin());
		if(status[u]==visited)
			continue;
		status[u]=visited;
		for(int i=0;i<adj[u].size();i++){
			ll v=adj[u][i].first,wt=adj[u][i].second;
			if(status[v]==intial && dis[v]>dis[u]+wt){
				dis[v]=dis[u]+wt;
				ms.insert(mp(wt,v));
			}
		}
	}
	for(int i=2;i<=n;i++)
		cout<<dis[i]<<" ";
	return 0;
}