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

ll arr[MAX],odd[4*MAX]={0};
void build(int node,int st,int en){
	if(st==en){
		odd[node]=arr[st]%2;
	}
	else{
		int mid=(st+en)/2;
		build(2*node,st,mid);
		build(2*node+1,mid+1,en);
		odd[node]=odd[2*node]+odd[2*node+1];
	}
}

void update(int node,int st,int en,int indx){
	if(st==en){
		odd[node]=arr[st]%2;
	}
	else{
		int mid=(st+en)/2;
		if(indx<=mid)
			update(2*node,st,mid,indx);
		else
			update(2*node+1,mid+1,en,indx);
		odd[node]=odd[2*node]+odd[2*node+1];
	}
}
int query(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return 0;
	if(st>=l&&en<=r)
		return odd[node];
	else{
		int mid=(st+en)/2;
		return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
	}
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==0){
			arr[x]=y;
			update(1,1,n,x);
		}
		else if(t==1){
			int ans=y-x+1-query(1,1,n,x,y);
			cout<<ans<<endl;
		}
		else{
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
	return 0;
}