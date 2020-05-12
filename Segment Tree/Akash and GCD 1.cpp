#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 5005
#define MAX2 1000005
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
int A[MAX2],tree[4*MAX2];
void build(int node,int l,int r){
	if(l==r){
		tree[node]=A[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node]=(tree[2*node]+tree[2*node+1])%MOD;
	}
}

void update(int node,int l,int r,int indx,int val){
	if(l==r){
		A[l]=tree[node]=val;
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			update(2*node,l,mid,indx,val);
		else
			update(2*node+1,mid+1,r,indx,val);
		tree[node]=(tree[2*node]+tree[2*node+1])%MOD;
	}
}

int query(int node,int s,int e,int l,int r){
	if(s>r||e<l)
		return 0;
	if(s>=l&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		return (query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r))%MOD;
	}
}
int main()
{
	fast;
	ll arr[MAX];
	for(int i=1;i<MAX;i++)
		arr[i]=i;
	for(int i=2;i<MAX;i++){
		for(int j=i;j<MAX;j+=i){
			arr[j]=(arr[j]-1+i+MOD)%MOD;
		}
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		A[i]=arr[A[i]];
	}
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		int x,y;
		cin>>x>>y;
		if(type=='C'){
			cout<<query(1,1,n,x,y)<<endl;
		}
		else{
			update(1,1,n,x,arr[y]);
		}
	}
	return 0;
}