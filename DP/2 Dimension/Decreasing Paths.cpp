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
int n,arr[MAX][MAX];
ll dp[MAX][MAX];
bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=n;
}

ll find_path(int x,int y)
{
	if(dp[x][y]==-1){
		dp[x][y]=1;
		if(check(x-1,y)&&arr[x-1][y]<arr[x][y])
			dp[x][y]=(dp[x][y]+find_path(x-1,y))%MOD;
		if(check(x+1,y)&&arr[x+1][y]<arr[x][y])
			dp[x][y]=(dp[x][y]+find_path(x+1,y))%MOD;
		if(check(x,y-1)&&arr[x][y-1]<arr[x][y])
			dp[x][y]=(dp[x][y]+find_path(x,y-1))%MOD;
		if(check(x,y+1)&&arr[x][y+1]<arr[x][y])
			dp[x][y]=(dp[x][y]+find_path(x,y+1))%MOD;
	}
	return dp[x][y];
}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=(ans+find_path(i,j))%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}