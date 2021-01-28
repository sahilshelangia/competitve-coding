/*
  Author: Sahil Yadav, IIITM Gwalior
*/
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAX 200005
#define endl '\n'
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<vector<ll> > matrix;
void reshape(matrix &mat, int n, int m)
{
	mat.resize(n);
	for(auto &i:mat) i.resize(m);
}
matrix operator*(matrix &mat1, matrix &mat2)
{
	int n1=mat1.size(), m1=mat1[0].size(), n2=mat2.size(), m2=mat2[0].size();
	assert(m1==n2);
	matrix ret;
	reshape(ret, n1, m2);
 
	for(int i=0; i<n1; ++i)
	    for(int j=0; j<m2; ++j){	
	    	ll sum=0;
	        for(int l=0; l<m1; ++l) sum=(sum+mat1[i][l]*mat2[l][j])%MOD;
	        ret[i][j]=sum;
	    }
	return ret;
}
matrix transpose(matrix &mat){
	matrix ans;
	int n=mat.size(),m=mat[0].size();
	reshape(ans,m,n);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			ans[j][i]=mat[i][j];
	}
	return ans;
}
matrix identity(int n){
	matrix ans;
	reshape(ans,n,n);
	for(int i=0;i<n;++i) ans[i][i]=1;
	return ans;
}
matrix power(matrix mat, ll n)
{
	matrix ans=identity(mat.size());
	while(n>0){
		if(n&1) 
			ans=ans*mat;
		mat=mat*mat;
		n>>=1;
	}
	return ans;
}
matrix trans, base;
int main()
{
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#endif
	
	return 0;
}