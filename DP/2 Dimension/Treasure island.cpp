#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 55
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
ll arr[MAX][MAX],cumm_sum[MAX][MAX];
ll dp[MAX][MAX][MAX][MAX];

ll min_cost(int x1,int y1,int x2,int y2){
	if(x1==x2&&y1==y2)
		return 0;
	if(dp[x1][y1][x2][y2]==-1){
		ll ans=1e17;
		for(int i=x1;i<x2;i++){
			ans=min(ans,min_cost(x1,y1,i,y2)+min_cost(i+1,y1,x2,y2)+cumm_sum[x2][y2]-cumm_sum[x2][y1-1]-cumm_sum[x1-1][y2]+cumm_sum[x1-1][y1-1]);
		}
		for(int j=y1;j<y2;j++){
			ans=min(ans,min_cost(x1,y1,x2,j)+min_cost(x1,j+1,x2,y2)+cumm_sum[x2][y2]-cumm_sum[x2][y1-1]-cumm_sum[x1-1][y2]+cumm_sum[x1-1][y1-1]);
		}
		dp[x1][y1][x2][y2]=ans;
	}
	return dp[x1][y1][x2][y2];
}
int main()
{
	fast;
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	memset(cumm_sum,0,sizeof(cumm_sum));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cumm_sum[i][j]=arr[i][j]+cumm_sum[i-1][j]+cumm_sum[i][j-1]-cumm_sum[i-1][j-1];
			// cout<<cumm_sum[i][j]<<" ";
		}
		// cout<<endl;
	}
	ll ans=min_cost(1,1,n,m);
	cout<<ans<<endl;
	return 0;
}