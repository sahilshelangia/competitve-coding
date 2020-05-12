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
pair <int,int>tree[4*MAX];
int arr[MAX],lazy[4*MAX]={0};
void push(int node){
	if(lazy[node]<0){
		tree[2*node].first+=lazy[node];
		tree[2*node].second+=lazy[node];
		lazy[2*node]+=lazy[node];
		tree[2*node+1].first+=lazy[node];
		tree[2*node+1].second+=lazy[node];
		lazy[2*node+1]+=lazy[node];
		lazy[node]=0;
	}
}

void build(int node,int l,int r){
	if(l==r){
		tree[node].first=tree[node].second=arr[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node].first=min(tree[2*node].first,tree[2*node+1].first);
		tree[node].second=max(tree[2*node].second,tree[2*node+1].second);
	}
}

void clearLazy(int node,int l,int r){
	if(l==r){
		arr[l]=tree[node].first;
		// tree[node].first=tree[node].second=arr[l];
	}
	else{
		push(node);
		int mid=(l+r)/2;
		clearLazy(2*node,l,mid);
		clearLazy(2*node+1,mid+1,r);
	}
}

void update(int node,int l,int r,int val){
	if(tree[node].first>val){
		tree[node].first--;
		tree[node].second--;
		lazy[node]+=-1;
	}
	else if(tree[node].second<=val)
		return ;
	else{
		push(node);
		int mid=(l+r)/2;
		update(2*node,l,mid,val);
		update(2*node+1,mid+1,r,val);
	}
}
int main()
{
	fast;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build(1,1,n);
	int m;
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		update(1,1,n,x);
	}
	clearLazy(1,1,n);

	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}