#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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
struct edge{
	int s,d,tim,cost;
};
int main()
{
	fast;
	int k,n,x;
	cin>>k>>n>>x;
	vector<edge>adj;
	for(int i=0;i<x;i++){
		int s,d,tim,cos;
		cin>>s>>d>>tim>>cos;
		cos+=tim*k;
		edge tmp;
		tmp.cost=cos;
		tmp.s=s;
		tmp.d=d;
		tmp.tim=tim;
		adj.pb(tmp);
		// tmp.s=d;
		// tmp.d=s;
		// adj.pb(tmp);		
	}
	int s,d;
	cin>>s>>d;
	int par[MAX],dis[MAX],timeTaken[MAX];
	for(int i=1;i<=n;i++)
		par[i]=nill,dis[i]=infi,timeTaken[i]=0;
	dis[s]=0;

	for(int j=1;j<n;j++){
		for(int i=0;i<adj.size();i++){
			int u=adj[i].s,v=adj[i].d,cost=adj[i].cost;
			if(u==s){
				if(dis[v]>dis[u]+cost){
					dis[v]=dis[u]+cost;
					par[v]=u;
					timeTaken[v]=timeTaken[u]+adj[i].tim;
				}
			}
			else{
				if(dis[v]>dis[u]+cost+k){
					dis[v]=dis[u]+cost+k;
					par[v]=u;
					timeTaken[v]=timeTaken[u]+adj[i].tim+1;
				}
			}
		}
	}
	if(dis[d]==infi){
		cout<<"Error"<<endl;
		return 0;
	}

	vector<int>path;
	int des=d;
	while(d!=nill){
		path.pb(d);
		d=par[d];
	}
	if(path.size()==2){
		cout<<"Error"<<endl;
		return 0;
	}
	for(int i=path.size()-1;i>0;i--){
		cout<<path[i]<<"->";
	}
	cout<<path[0]<<" "<<timeTaken[des]<<" "<<dis[des]<<endl;

	return 0;
}