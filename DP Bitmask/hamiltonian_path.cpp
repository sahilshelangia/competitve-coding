#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 105
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
ll n,m;
ll cost[MAX][MAX];

ll find_min(ll mask,ll vertex){
	// cout<<mask<<" "<<vertex<<endl;
	if(vertex>n)
		return 0;
	if(__builtin_popcount(mask)==n){
		return 0;
	}
	ll ans=MOD;
	for(int i=1;i<=n;i++){
		if(cost[vertex][i]!=-1&&((mask&(1<<i))==0)){
			// cout<<"Going=>"<<vertex<<" "<<i<<endl;
			ans=min(ans,cost[vertex][i]+find_min(mask|(1<<i),i));
		}
	}
	return ans;
}
int main()
{
	fast;
	memset(cost,-1,sizeof(cost));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		if(cost[u][v]!=-1){
			cost[u][v]=cost[v][u]=min(w,cost[u][v]);
		}
		else
		cost[u][v]=cost[v][u]=w;
	}
	ll ans=MAX;
	for(int i=1;i<=n;i++)
		ans=min(ans,find_min(1<<i,i));
	cout<<ans<<endl;
	return 0;
}