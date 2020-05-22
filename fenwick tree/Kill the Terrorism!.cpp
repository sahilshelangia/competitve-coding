#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 200005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int val[MAX];
std::vector<int>tree[4*MAX];
void combine(int node){
	int l=2*node,r=2*node+1,i=0,j=0,la=tree[l].size(),lb=tree[r].size();
	while(i<la&&j<lb){
		if(tree[l][i]<tree[r][j]){
			tree[node].pb(tree[l][i]);
			++i;
		}
		else{
			tree[node].pb(tree[r][j]);
			++j;
		}
	}
	while(i<la){
		tree[node].pb(tree[l][i]);
		++i;
	}
	while(j<lb){
		tree[node].pb(tree[r][j]);
		++j;
	}
}
void build(int node,int l,int r){
	if(l==r){
		tree[node].pb(val[l]);
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		combine(node);
	}
}
int query(int node,int st,int en,int l,int r,int val){
	if(st>r||en<l)
		return 0;
	if(st>=l&&en<=r){
		int x=upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
		return x;
	}
	int mid=(st+en)/2;
	return query(2*node,st,mid,l,r,val)+query(2*node+1,mid+1,en,l,r,val);
}

int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	int arr[n+1],power[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		if(i!=1)
			arr[i]=arr[i]&arr[i-1];
	}
	for(int i=1;i<=n;++i)
		cin>>power[i];

	for(int i=1;i<=n;++i)
		cin>>val[i];
	build(1,1,n);
	for(int i=1;i<=n;++i){
		int l=1,h=n,ans=-1;
		while(l<=h){
			int m=(l+h)/2;
			int x=query(1,1,n,1,m,arr[i]);
			if(x>=power[i]){
				ans=m;
				h=m-1;
			}
			else
				l=m+1;
		}
		cout<<ans<<" ";
	}
	return 0;
}