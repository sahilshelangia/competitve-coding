#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::vector<int>adj[MAX];
int st[MAX],en[MAX],indx[MAX],cnt=1;
void dfs(int u,int par){
	indx[u]=st[u]=++cnt;
	for(int v:adj[u]){
		if(v!=par)
			dfs(v,u);
	}
	en[u]=cnt;
}

ll bit[MAX];
void update(int x,ll val){
	while(x<MAX){
		bit[x]+=val;
		x+=x&-x;
	}
}
ll query(int x){
	ll ans=0;
	while(x>0){
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,q;
	cin>>n>>q;
	int deg[n+1]={0};
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		deg[v]++;
		adj[u].pb(v);
	}
	int root=-1;
	for(int i=1;i<=n;++i){
		if(deg[i]==0)
			root=i;
	}
	dfs(root,-1);
	ll profit[n+1];
	for(int i=1;i<=n;++i){
		cin>>profit[i];
		update(indx[i],profit[i]);
	}

	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int x,y;
			cin>>x>>y;
			update(indx[x],y-profit[x]);
			profit[x]=y;
		}
		else{
			int x;
			cin>>x;
			ll ans=query(en[x])-query(st[x]-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}