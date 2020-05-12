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
std::vector<pair<int,int> > adj[MAX],q1[MAX],q2[MAX];
int status[MAX]={intial},time_in[MAX],time_out[MAX],timer=0,dp[MAX][30],tree[4*MAX]={0},ans[MAX]={0};

void update(int node,int l,int r,int indx,int val){
	if(l==r){
		tree[node]+=val;
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			update(2*node,l,mid,indx,val);
		else
			update(2*node+1,mid+1,r,indx,val);

		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

int query(int node,int s,int e,int l,int r){
	if(s>r||e<l)
		return 0;
	if(s>=l&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		return query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r);
	}
}
void dfs(int u,int par){
	status[u]=visited;
	time_in[u]=++timer;
	dp[u][0]=par;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		if(status[v]==intial){
			dfs(v,u);
		}
	}
	time_out[u]=++timer;
}

void dfs1(int u,int len){
	if(len!=0)
		update(1,1,MAX,len,1);
	for(int i=0;i<q1[u].size();i++){
	 	int qy=q1[u][i].second,x=q1[u][i].first;
        ans[qy]+= query(1,1,1000000,1,x);
    }

    for(int i=0;i<q2[u].size();i++){
	 	int qy=q2[u][i].second,x=q2[u][i].first;
        // ans[qy]= ans[qy]-2*query(1,1,1000000,1,x);
    }

	status[u]=visited;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		if(status[v]==intial){
			dfs1(v,adj[u][i].second);
		}
	}
	update(1,1,MAX,len,-1);
}
bool is_ancestor(int u,int v){
	if(time_in[u]<=time_in[v]&&time_out[u]>=time_out[v])
		return true;
	return false;
}

int lca(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;

	for(int i=21;i>=0;i--){
		if(!is_ancestor(dp[u][i],v))
			u=dp[u][i];
	}
	return dp[u][0];
}

int main()
{
	// fast;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb(make_pair(v,w));
		adj[v].pb(make_pair(u,w));
	}
	for(int i=0;i<MAX;i++)
		for(int j=0;j<=21;j++)
			dp[i][j]=1;
	dfs(1,1);
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}

	for(int i=1;i<=q;i++){
		int a,b,len;
		cin>>a>>b>>len;
		q1[a].pb(make_pair(len,i));
		q1[b].pb(make_pair(len,i));
		q2[lca(a,b)].pb(make_pair(len,i));
		// cout<<a<<" "<<b<<":"<<lca(a,b)<<endl;
	}
	memset(status,intial,sizeof(status));
	dfs1(1,0);
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}