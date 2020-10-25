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
#define MAX 5005
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int unhappy[MAX][MAX],bit[MAX],dp[MAX][MAX],opt[MAX][MAX];
void update(int indx,int val){
	while(indx<MAX){
		bit[indx]+=val;
		indx=indx+(indx&-indx);
	}
}
int query(int indx){
	int ans=0;
	while(indx){
		ans+=bit[indx];
		indx=indx-(indx&-indx);
	}
	return ans;
}
void preprocess(int n){
	std::vector<int> v(n+1),tmp(n+1,0);
	for(int i=1;i<=n;++i){
		cin>>v[i];
		tmp[i]=v[i];
	}
	sort(all(tmp));
	unordered_map<int,int>cc;
	cc[tmp[1]]=1;
	for(int i=2;i<=n;++i){
		if(tmp[i]==tmp[i-1])
			cc[tmp[i]]=cc[tmp[i-1]];
		else
			cc[tmp[i]]=cc[tmp[i-1]]+1;
	}
	for(int i=1;i<=n;++i)
		v[i]=cc[v[i]];

	for(int i=1;i<=n;++i){
		memset(bit,0,sizeof(bit));
		for(int j=i;j<=n;++j){
			update(v[j],1);
			unhappy[i][j]=query(MAX)-query(v[j]);
			if(j>i)
				unhappy[i][j]+=unhappy[i][j-1];
		}
	}
}
void compute(int k,int L,int R,int optL,int optR){
	// cout<<L<<" "<<R<<" : "<<optL<<" "<<optR<<endl;
	if(L>R)
		return ;
	int m=(L+R)/2;
	int optk=-1,ans=1e9;
	for(int i=max(optL,k);i<=min(m,optR);++i){
		if(dp[k-1][i]+unhappy[i+1][m]<ans){
			ans=dp[k-1][i]+unhappy[i+1][m];
			optk=i;
		}
	}
	dp[k][m]=ans;
	// cout<<m<<" "<<optk<<"="<<ans<<endl;
	// opt[k][m]=optk;
	compute(k,L,m-1,optL,optk);
	compute(k,m+1,R,optk,optR);
}
int solve(int n,int k){
	for(int i=1;i<=n;++i)
		dp[1][i]=unhappy[1][i];
	for(int i=2;i<=k;++i)
		compute(i,1,n,1,n);
	return dp[k][n];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,k;
	cin>>n>>k;
	preprocess(n);
	cout<<solve(n,k);
	return 0;
}