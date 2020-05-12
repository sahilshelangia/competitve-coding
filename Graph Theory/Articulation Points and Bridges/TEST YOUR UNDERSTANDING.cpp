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
std::vector<int> adj[MAX];
std::vector<PII> bridge;
bool ap[MAX];
int dis[MAX],low[MAX],par[MAX],status[MAX];
void articultionPoint(int u,int tim){
	dis[u]=low[u]=tim+1;
	status[u]=visited;
	int child=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial){
			child++;
			par[v]=u;
			articultionPoint(v,tim+1);
			low[u]=min(low[u],low[v]);
			if(par[u]==nill&&child>1)
				ap[u]=true;
			if(par[u]!=nill&&low[v]>=dis[u])
				ap[u]=true;
			if(low[v]>dis[u])
				bridge.pb(mp(min(u,v),max(u,v)));
		}
		else if(par[u]!=i)
			low[u]=min(low[u],dis[v]);
	}
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset(ap,false,sizeof(ap));
	memset(par,nill,sizeof(par));
	memset(status,intial,sizeof(status));
	articultionPoint(0,0);
	std::vector<int> ap_sorted;
	for(int i=0;i<n;i++){
		if(ap[i])
			ap_sorted.pb(i);
	}
	cout<<ap_sorted.size()<<endl;
	sort(ap_sorted.begin(),ap_sorted.end());
	for(int i=0;i<ap_sorted.size();i++)
		cout<<ap_sorted[i]<<" ";
	cout<<endl;

	sort(bridge.begin(),bridge.end());
	cout<<bridge.size()<<endl;
	for(int i=0;i<bridge.size();i++)
		cout<<bridge[i].first<<" "<<bridge[i].second<<endl;


	return 0;
}