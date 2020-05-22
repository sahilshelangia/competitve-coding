#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 300009
#define infi 1e12
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::vector<int>adj[MAX];
int val[MAX],prime[MAX],indx[MAX],st[MAX],en[MAX],cnt;
int check(int x){
	if(x<=1)
		return 0;
	return prime[x];
}
void dfs(int u,int par){
	cnt++;
	st[u]=indx[u]=cnt;
	for(int v:adj[u]){
		if(v!=par)
			dfs(v,u);
	}
	en[u]=cnt;
}

int bit[MAX];
void intial(int n){
	cnt=0;
	for(int i=0;i<MAX;++i){
		adj[i].clear();
		bit[i]=0;
	}
}
void update(int x,int val){
	while(x<MAX){
		bit[x]+=val;
		x+=x&-x;
	}
}
int query(int x){
	int ans=0;
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
	for(int i=0;i<MAX;++i)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i<MAX;++i){
		if(prime[i]==1){
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=0;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		intial(n);
		for(int i=1;i<=n;++i){
			ll x;
			cin>>x;
			x=check(x);
			val[i]=x;
		}
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1,1);
		int arr[n+1]={0};
		for(int i=1;i<=n;++i){
			// arr[indx[i]]=val[i];
			update(indx[i],val[i]);
		}
		while(q--){
			int type;
			cin>>type;
			if(type==1){
				int u,x;
				cin>>u>>x;
				update(indx[u],-val[u]);
				val[u]=check(x);
				update(indx[u],val[u]);
			}
			else{
				int u;
				cin>>u;
				int ans=query(en[u])-query(st[u]-1);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}