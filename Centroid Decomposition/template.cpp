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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
set<int>adj[MAX];
int par[MAX],sub[MAX];

int dfs1(int u,int p){
	sub[u]=1;
	for(int v:adj[u]){
		if(v!=p)
			sub[v]+=dfs1(v,u);
	}
	return sub[u];
}

int dfs(int u,int p,int n){
	for(int v:adj[u]){
		if(sub[v]>n/2)
			return dfs(v,u,n);
	}
	return u;
}
void decompose(int u,int p){
	int n=dfs1(u,-1);
	int centroid=dfs(u,p,n);
	par[centroid]=p;
	for(int v:adj[u]){
		adj[v].erase(adj[u].find(u));
		decompose(v,centroid);
	}
}

int main()
{
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#endif

	return 0;
}