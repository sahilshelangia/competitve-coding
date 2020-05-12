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
int timeIn[MAX],timeOut[MAX],tim=0,status[MAX];
void dfs(int u){
	timeIn[u]=++tim;
	status[u]=visited;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial){
			dfs(v);
		}
	}
	timeOut[u]=++tim;
}
int main()
{
	fast;
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(status,intial,sizeof(status));
	dfs(1);
	int q;
	cin>>q;
	while(q--){
		int type,a,b;
		cin>>type>>a>>b;
		if(type==0){
			if(timeIn[a]<timeIn[b]&&timeOut[a]>timeOut[b])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			if(timeIn[b]<timeIn[a]&&timeOut[b]>timeOut[a])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}