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
int n,m;
bool check(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main()
{
	fast;
	cin>>n>>m;
	int room[n][m];
	memset(room,0,sizeof(room));
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x,y,val;
		cin>>x>>y>>val;
		room[x][y]=val;
	}

	// allowed to right and down

	ll dp[n][m];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(room[i][j]>=0){
				if(check(i+1,j)&&room[i+1][j]!=-1)
					dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
				if(check(i,j+1)&&room[i][j+1]!=-1)
					dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
				
				if(room[i][j]>1){
					int k=room[i][j];
					if(check(i+k,j)&&room[i+k][j]!=-1)
						dp[i+k][j]=(dp[i+k][j]+dp[i][j])%MOD;
					if(check(i,j+k)&&room[i][j+k]!=-1)
						dp[i][j+k]=(dp[i][j+k]+dp[i][j])%MOD;
				}	
			}
		}
	}

	cout<<dp[n-1][m-1]<<endl;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	return 0;
}