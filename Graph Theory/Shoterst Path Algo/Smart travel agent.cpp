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
int main()
{
	fast;
	int n,r;
	cin>>n>>r;
	std::vector<PII> adj[n+1];
	for(int i=0;i<r;i++){
		int u,v,p;
		cin>>u>>v>>p;
		adj[u].pb(mp(v,p));
		adj[v].pb(mp(u,p));
	}

	ll src,dest,tour;
	cin>>src>>dest>>tour;

	ll status[n+1],cap[n+1],par[n+1];
	for(int i=1;i<=n;i++)
		cap[i]=0,status[i]=intial,par[i]=nill;

	priority_queue<PII>pq;
	cap[src]=infi;
	pq.push(mp(cap[src],src));
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(status[u]==visited)
			continue;
		status[u]=visited;
		for(int i=0;i<adj[u].size();i++){
			ll v=adj[u][i].first,edgeCap=adj[u][i].second;
			if(status[v]==intial&&cap[v]<=min(cap[u],edgeCap)){
				if(cap[v]<min(cap[u],edgeCap)){
					cap[v]=min(cap[u],edgeCap);
					par[v]=u;
					pq.push(mp(cap[v],v));	
				}
				else{
					par[v]=min(par[v],u);
				}
			}
		}
	}
	std::vector<int> path;
	int d=dest;
	while(d!=nill){
		path.pb(d);
		d=par[d];
	}
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	cout<<endl;
	ll ans=ceil(tour*1.0/(cap[dest]-1));
	cout<<ans<<endl;
	return 0;
}