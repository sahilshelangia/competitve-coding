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
#define MAX 8005
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll prefix[MAX],dp[808][MAX];
ll cost(int l,int r){
	return (prefix[r]-prefix[l-1])*(r-l+1);
}
void inputs(int n){
	for(int i=1;i<=n;++i){
		cin>>prefix[i];
		prefix[i]+=prefix[i-1];
	}
}
void compute(int d,int l,int r,int optL,int optR){
	if(l>r)
		return ;
	int m=(l+r)/2;
	ll optk=-1,ans=1e16;
	for(int i=optL;i<=optR;++i){
		if(dp[d-1][i]+cost(i+1,m)<ans){
			ans=dp[d-1][i]+cost(i+1,m);
			optk=i;
		}
	}
	dp[d][m]=ans;
	compute(d,l,m-1,optL,optk);
	compute(d,m+1,r,optk,optR);
}
ll solve(int n,int k){
	for(int i=1;i<=n;++i)
		dp[1][i]=cost(1,i);
	for(int i=2;i<=k;++i){
		compute(i,1,n,1,n);
	}
	return dp[k][n];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,k;
	cin>>n>>k;
	inputs(n);
	cout<<solve(n,k)<<endl;
	return 0;
}