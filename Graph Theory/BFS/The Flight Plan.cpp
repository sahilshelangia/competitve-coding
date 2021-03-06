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
int main()
{
	fast;
	int n,m,t,c;
	cin>>n>>m>>t>>c;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int x,y;
	cin>>x>>y;
	int status[MAX],par[MAX];
	memset(status,intial,sizeof(status));
	memset(par,-1,sizeof(par));
	queue<int>q;
	q.push(x);
	status[x]=waiting;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		status[u]=visited;
		sort(adj[u].begin(),adj[u].end());
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(status[v]==intial){
				par[v]=u;
				q.push(v);
				status[v]=waiting;
			}
		}
	}
	std::vector<int>path;
	int tmp=y;
	while(par[tmp]!=-1){
		path.pb(tmp);
		tmp=par[tmp];
	}
	path.pb(x);
	reverse(path.begin(),path.end());
	cout<<path.size()<<endl;
	for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;

	return 0;
}