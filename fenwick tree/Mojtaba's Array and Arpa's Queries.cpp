#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 500005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll tree[4*MAX],arr[MAX],k,dif[MAX],tree2[4*MAX];
 
void build2(int node,int l,int r){
	if(l==r){
		tree2[node]=dif[l];
	}
	else{
		int m=(l+r)/2;
		build2(2*node,l,m);
		build2(2*node+1,m+1,r);
		tree2[node]=min(tree2[2*node],tree2[2*node+1]);
	}
}
 
ll query2(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return 1e7;
	if(st>=l&&en<=r)
		return tree2[node];
	else{
		int mid=(st+en)/2;
		return min(query2(2*node,st,mid,l,r),query2(2*node+1,mid+1,en,l,r));
	}
}
 
void build(int node,int l,int r){
	if(l==r){
		tree[node]=arr[l]%k;
	}
	else{
		int m=(l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node]=tree[2*node]*tree[2*node+1]%k;
	}
}
ll query(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return 1;
	if(st>=l&&en<=r)
		return tree[node];
	else{
		int mid=(st+en)/2;
		return query(2*node,st,mid,l,r)*query(2*node+1,mid+1,en,l,r)%k;
	}
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	ll n,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	int en[n+1]={0};
	build(1,1,n);
	ll ans=0,prev=1;
	for(int i=1;i<=n;++i){
		while(prev<=n){
			if(query(1,1,n,i,prev)==0)
				break;
			else
				prev++;
		}
		if(prev<=n)
			en[prev]=i;
		dif[i]=prev-i+1;
		// cout<<"dif"<<i<<": "<<dif[i]<<endl;
		// cout<<i<<": "<<prev<<endl;
		prev=max(prev,(ll)i);
	}
	// for(int i=1;i<=n;++i)
	// 	cout<<en[i]<<" ";
	for(int i=2;i<=n;++i)
		en[i]=max(en[i-1],en[i]);
 
	build2(1,1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		r=en[r];
		// cout<<l<<":"<<r<<endl;
		if(l>r)
			cout<<-1<<" ";
		else{
			cout<<query2(1,1,n,l,r)<<" ";
		}
	}
	return 0;
}