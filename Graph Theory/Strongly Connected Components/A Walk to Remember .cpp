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
std::vector<int>adj[MAX],radj[MAX];
int status[MAX];
stack<int>s;
std::vector<int> scc;

void dfs(int u){
	status[u]=visited;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial)
			dfs(v);
	}
	s.push(u);
}

void rdfs(int u){
	status[u]=visited;
	scc.pb(u);
	for(int i=0;i<radj[u].size();i++){
		int v=radj[u][i];
		if(status[v]==intial)
			rdfs(v);
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
		radj[v].pb(u);
	}
	memset(status,intial,sizeof(status));
	for(int i=1;i<=n;i++){
		if(status[i]==intial)
			dfs(i);
	}	

	memset(status,intial,sizeof(status));
	int ans[MAX]={0};
	while(!s.empty()){
		int u=s.top();
		s.pop();
		if(status[u]==intial){
			scc.clear();
			rdfs(u);
			if(scc.size()==1){
				ans[scc[0]]=0;
			}
			else{
				for(int i=0;i<scc.size();i++)
					ans[scc[i]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}