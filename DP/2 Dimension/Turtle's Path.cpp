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
#define visite 2
#define nill -1
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;

std::vector< pair<int,int> > path;
int n,m;
bool prime[MAX],visited[1005][1005];
int arr[1005][1005];
bool check(int x,int y){
	if(x>0&&x<=n&&y>0&&y<=m&&prime[arr[x][y]]==true)
		return true;
	return false;
}
bool dfs(int x,int y){
	if(visited[x][y])
		return false;
	if(x==n&&y==m){
		path.pb(mp(x,y));
		visited[x][y]=true;
		return true;
	}
	if(check(x+1,y+1)){
		if(dfs(x+1,y+1)){
			path.pb(mp(x,y));
			visited[x][y]=true;
			return true;
		}
	}
	if(check(x+1,y)){
		if(dfs(x+1,y)){
			path.pb(mp(x,y));
			visited[x][y]=true;
			return true;
		}
	}
	if(check(x,y+1)){
		if(dfs(x,y+1)){
			path.pb(mp(x,y));
			visited[x][y]=true;
			return true;
		}
	}
	visited[x][y]=true;
	return false;
}
int main()
{
	fast;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];
	}
	memset(prime,true,sizeof(prime));
	memset(visited,false,sizeof(visited));
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++){
		if(prime[i]){
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=false;
		}
	}

	ll dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(prime[arr[i][j]]){
				dp[i][j]=(dp[i-1][j-1]+dp[i][j-1]+dp[i-1][j])%MOD;
			}
			else
				dp[i][j]=0;
		}
	}
	cout<<dp[n][m]<<endl;
	if(dfs(1,1)){
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i].first<<" "<<path[i].second<<endl;
		}
	}
	return 0;
}