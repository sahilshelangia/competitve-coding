#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 200005
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
int n,dp[MAX][20],status[MAX]={0},timer=0,time_in[MAX],time_out[MAX],count_prime[MAX]={0},l;
std::vector<int>adj[MAX];
bool prime[MAX];

void seive(){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++){
		if(prime[i]){
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=false;
		}
	}
}

void dfs(int u)
{	
	time_in[u]=++timer;
	status[u]=visited;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(status[v]==intial){
			count_prime[v]=count_prime[u];
			if(prime[v])
				count_prime[v]++;
			dp[v][0]=u;
			dfs(v);
		}
	}

	time_out[u]=++timer;
}

bool is_ancestor(int u,int v){
	return time_in[u]<=time_in[v]&&time_out[u]>=time_out[v];
}

int lcs(int u,int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;
	for(int i=l;i>=0;i--){
		if(!is_ancestor(dp[u][i],v))
			u=dp[u][i];
	}
	return dp[u][0];
}
int main()
{
	fast;
	seive();
	cin>>n;
	l=ceil(log2(n));
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dp[1][0]=1;
	count_prime[1]=0;
	dfs(1);
	for(int i=1;i<=l;i++){
		for(int j=1;j<=n;j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	}

	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" "<<count_prime[i]<<endl;
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=count_prime[u]+count_prime[v]-2*count_prime[lcs(u,v)];
		// cout<<"LCS:"<<lcs(u,v)<<endl;
		// cout<<count_prime[u]<<" "<<count_prime[v]<<endl;
		if(prime[lcs(u,v)])
			ans++;
		cout<<ans<<'\n';
	}

	return 0;
}	