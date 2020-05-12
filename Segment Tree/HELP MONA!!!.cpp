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
int arr[MAX],tree[4*MAX];

void build(int node,int l,int r){
	if(l==r){
		tree[node]=arr[l]%2;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void update(int node,int l,int r,int indx){
	if(l==r){
		arr[l]++;
		tree[node]=arr[l]%2;
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			update(2*node,l,mid,indx);
		else
			update(2*node+1,mid+1,r,indx);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
int query(int node,int l,int r,int k){
	if(tree[node]<k)
		return -1;
	if(l==r)
		return l;
	int mid=(l+r)/2;
	if(tree[2*node]>=k)
		return query(2*node,l,mid,k);
	else
		return query(2*node+1,mid+1,r,k-tree[2*node]);
}
int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build(1,1,n);
	while(q--){
		int type,x;
		cin>>type>>x;
		if(type==1){
			update(1,1,n,x);
		}
		else{
			int ans=query(1,1,n,x);
			cout<<ans<<endl;
		}
	}
	return 0;
}