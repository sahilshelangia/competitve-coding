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
std::vector<PII>adj[MAX];
int main()
{
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<MAX;i++)
			adj[i].clear();
		int n;
		cin>>n;
		for(int i=1;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		int xorSum[MAX],leaf[MAX];
		memset(leaf,0,sizeof(leaf));
		queue<int>q;
		int status[MAX];
		memset(status,intial,sizeof(status));
		status[1]=waiting;
		q.push(1);
		xorSum[1]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			bool flag=true;
			for(int i=0;i<adj[u].size();i++){
				int v=adj[u][i].first;
				int wt=adj[u][i].second;
				if(status[v]==intial){
					flag=false;
					q.push(v);
					status[v]=waiting;
					xorSum[v]=xorSum[u]^wt;
				}
			}
			if(flag)
				leaf[u]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(leaf[i]==1&&xorSum[i]%2==1)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}