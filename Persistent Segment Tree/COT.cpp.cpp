// https://www.spoj.com/problems/COT/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
const ll MOD=1e9+7;
#define MAX 200005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
vector <ll> adj[MAX],wt;
int maxi=0;
map <ll, ll> M;
ll RM[MAX],dp[MAX][21],status[MAX]={0},tin[MAX]={0},tout[MAX]={0},tim=0;
struct node
{
	int count;
	node *left,*right;
	node(int cnt,node *a,node *b){
		count=cnt;
		left=a;
		right=b;
	}	
	node(){
		count=0;
		left=NULL;
		right=NULL;
	}
};
node *root[MAX];
node *null = new node(0, NULL, NULL);
int valf(node *a){
	if(a!=NULL)
		return a->count;
	return 0;
}
node * insert(int l,int r,node *purana,node *naya,int pos){
	naya=new node();
	if(l==r){
		naya->count=valf(purana)+1;
		return naya;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		if(purana){
			naya->right=purana->right;
			purana=purana->left;
		}
		naya->left=insert(l,mid,purana,naya,pos);
	}
	else{
		if(purana){
			naya->left=purana->left;
			purana=purana->right;
		}
		naya->right=insert(mid+1,r,purana,naya,pos);
	}
	naya->count=valf(naya->left)+valf(naya->right);
	return naya;
}

int query(node *a,node *b,node *c,node *d,int l,int r,int k){
	if(l==r)
		return l;
	int cnt=valf(a->left)+valf(b->left)-valf(c->left)-valf(d->left);
	int mid=(l+r)/2;
	if(cnt>=k)
		return query(a->left,b->left,c->left,d->left,l,mid,k);
	return query(a->right,b->right,c->right,d->right,mid+1,r,k-cnt);
}
void coordinate_compression(int n){
	for(int i=0;i<n;++i)
		M[wt[i]];
	for(auto x:M){
		M[x.first]=maxi;
		RM[maxi]=x.first;
		maxi++;
	}
}
void dfs(int u,int par){
	dp[u][0]=par;
	status[u]=visited;
	tin[u]=++tim;
	node *purana=(u==0?null:root[par]);
	root[u]=insert(0,maxi,purana,root[u],M[wt[u]]);
	for(int v:adj[u]){
		if(status[v]==intial){
			dfs(v,u);
		}
	}
	tout[u]=++tim;
}
bool is_ancestor(int u,int v){
	if(tin[u]<=tin[v]&&tout[u]>=tout[v])
		return true;
	return false;
}
int LCA(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;
	for(int i=19;i>=0;--i){
		if(!is_ancestor(dp[u][i],v))
			u=dp[u][i];
	}
	return dp[u][0];
}

int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,m;
	cin>>n>>m;
	wt.resize(n);
	for(auto &i:wt)
		cin>>i;
	coordinate_compression(n);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	null->left=null->right=null;
	dfs(0,0);
	for(int j=1;j<=20;++j){
		for(int i=0;i<n;++i)
			dp[i][j]=dp[dp[i][j-1]][j-1];
	}	
	while(m--){
		int u,v,k;
		cin>>u>>v>>k;
		u--;v--;
		int lca=LCA(u,v);
		int ans=query(root[u],root[v],root[lca],(lca==0?null:root[dp[lca][0]]),0,maxi,k);
		cout<<RM[ans]<<endl;
	}
	return 0;
}