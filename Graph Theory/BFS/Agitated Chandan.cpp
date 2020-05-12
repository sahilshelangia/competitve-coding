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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		std::vector<PII>adj[MAX];
		for(int i=1;i<n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].pb(mp(v,w));
			adj[v].pb(mp(u,w));
		}
		int source=1;
		queue<int>q;
		int status[MAX],dis[MAX];
		memset(status,intial,sizeof(status));
		q.push(source);
		dis[source]=0;
		status[source]=waiting;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<adj[u].size();i++){
				int v=adj[u][i].first;
				if(status[v]==intial){
					q.push(v);
					status[v]=waiting;
					dis[v]=dis[u]+adj[u][i].second;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dis[source]<dis[i])
				source=i;
		}

		while(!q.empty())
			q.pop();
		memset(status,intial,sizeof(status));
		q.push(source);
		dis[source]=0;
		status[source]=waiting;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<adj[u].size();i++){
				int v=adj[u][i].first;
				if(status[v]==intial){
					q.push(v);
					status[v]=waiting;
					dis[v]=dis[u]+adj[u][i].second;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dis[source]<dis[i])
				source=i;
		}
		ll cost=0;
		if(dis[source]<100)
			cost=0;
		else if(dis[source]>100&&dis[source]<1000)
			cost=100;
		else if(dis[source]>1000&&dis[source]<10000)
			cost=1000;
		else 
			cost=10000;
		cout<<cost<<" "<<dis[source]<<endl;
			
	}
	return 0;
}