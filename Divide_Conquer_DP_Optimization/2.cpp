/*
  Author: Sahil Yadav, IIITM Gwalior
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define MAX 4001
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int arr[MAX][MAX],dp[MAX][MAX],dp2[MAX][MAX];
void preprocess(int n){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			char x;
			cin>>x;
			arr[i][j]=int(x-'0');
		}
	}
	int cumm[n+1][n+1];
	memset(cumm,0,sizeof(cumm));
	memset(dp2,-1,sizeof(dp2));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cumm[i][j]=arr[i][j]+cumm[i-1][j]+cumm[i][j-1]-cumm[i-1][j-1];
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=cumm[j][j]-cumm[j][i-1]-cumm[i-1][j]+cumm[i-1][i-1];
			dp[i][j]/=2;		
		}
	}
}


void compute(int d,int L,int R,int optL,int optR){
	if(L>R)
		return ;
	int m=(L+R)/2;
	int optK=-1,ans=1e8;
	for(int i=optL;i<=optR;++i){
		if(dp2[d-1][i]+dp[i+1][m]<ans){
			ans=dp2[d-1][i]+dp[i+1][m];
			optK=i;
		}
	}
	dp2[d][m]=ans;
	compute(d,L,m-1,optL,optK);
	compute(d,m+1,R,optK,optR);
}

int solve(int n,int k){
	for(int i=1;i<=n;++i)
		dp2[1][i]=dp[1][i];
	for(int i=2;i<=k;++i)
		compute(i,1,n,1,n);
	return dp2[k][n];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,k;
	cin>>n>>k;
	preprocess(n);
	cout<<solve(n,k)<<endl;
	return 0;
}

/*
9 3
0 0 0 0 1 1 1 1 1
0 0 0 0 1 1 1 1 1
0 0 0 0 1 1 1 1 1
0 0 0 0 1 1 1 1 1
1 1 1 1 0 0 1 1 1
1 1 1 1 0 0 1 1 1
1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 0 0 0
*/