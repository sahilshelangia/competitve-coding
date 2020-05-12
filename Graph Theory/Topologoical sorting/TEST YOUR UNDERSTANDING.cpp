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
	int n,m;
	cin>>n>>m;
	std::vector<int>adj[n+1];
	int inDegree[n+1]={0},status[n+1]={0};
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		inDegree[v]++;
	}
	set<int>s;
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0)
			s.insert(i),status[i]=visited;
	}
	std::vector<int>ans;
	while(s.size()!=0){
		int u=*s.begin();
		s.erase(s.begin());
		ans.pb(u);
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(status[v]==intial){
				inDegree[v]--;
				if(inDegree[v]==0){
					status[v]=visited;
					s.insert(v);
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}