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

int tree[4*MAX],arr[MAX];
void build(int node,int l,int r){
	if(l==r){
		tree[node]=arr[l];
		return ;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}

void update(int node,int l,int r,int idx,int val){
	if(l==r){
		arr[l]=tree[node]=val;
		return ;
	}
	else{
		int mid=(l+r)/2;
		if(idx>=l&&idx<=mid)
			update(2*node,l,mid,idx,val);
		else
			update(2*node+1,mid+1,r,idx,val);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}

int query(int node,int s,int e,int l,int r){
	if(r<s||e<l)
		return MAX;
	else if(l<=s&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		int p1=query(2*node,s,mid,l,r);
		int p2=query(2*node+1,mid+1,e,l,r);
		return min(p1,p2);
	}
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
		char type;
		cin>>type;
		if(type=='q'){
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
		else{
			int idx,val;
			cin>>idx>>val;
			update(1,1,n,idx,val);
		}
	}
	return 0;
}