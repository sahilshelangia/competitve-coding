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
std::vector<pair<int,int> > adj[MAX];
int dis[MAX]={0},time_in[MAX],time_out[MAX],timer=0,status[MAX]={0},arr[MAX],cntr=1;
int final[MAX];
vector<int>tree[4*MAX];
void dfs(int u){
	arr[cntr]=u;
	final[cntr]=dis[u];
	cntr++;
	status[u]=visited;
	time_in[u]=++timer;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		if(status[v]==intial){
			dis[v]=dis[u]+adj[u][i].second;
			dfs(v);
		}
	}
	time_out[u]=++timer;
}

std::vector<int> combine(std::vector<int> v1,std::vector<int> v2){
	std::vector<int> v;
	int len1=v2.size(),len2=v2.size(),i=0,j=0;
	while(i<len1&&j<len2){
		if(v1[i]<=v2[j]){
			v.pb(v1[i]);
			i++;
		}
		else{
			v.pb(v2[j]);
			j++;
		}
	}
	while(i<len1){
		v.pb(v1[i]);
		i++;
	}
	
	while(j<len2){
		v.pb(v2[j]);
		j++;
	}
	return v;

}

void build(int node,int l,int r){
	if(l==r){
		tree[node].pb(final[l]);
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node]=combine(tree[2*node],tree[2*node+1]);
	}
}

int 
int main()
{
	fast;
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].pb(mp(b,w));
		adj[b].pb(mp(a,w));
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" "<<time_in[arr[i]]<<" "<<time_out[arr[i]]<<endl;
	}

	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int v,k;
		cin>>v>>k;
		// find l and r in final arr
	}
	return 0;
}