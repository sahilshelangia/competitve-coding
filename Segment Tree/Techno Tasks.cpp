#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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
struct info
{
	int left,right,ans;
};
int arr[MAX];
info tree[4*MAX];

void build(int node,int l,int r){
	if(l==r){
		tree[node].ans=tree[node].left=tree[node].right=arr[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		if(tree[2*node].right==1&&tree[2*node+1].left==1){
			tree[node].ans=tree[2*node].ans+tree[2*node+1].ans-1;
			tree[node].left=tree[2*node].left;
			tree[node].right=tree[2*node+1].right;
		}
		else{
			tree[node].ans=tree[2*node].ans+tree[2*node+1].ans;
			tree[node].left=tree[2*node].left;
			tree[node].right=tree[2*node+1].right;	
		}
	}
}

void update(int node,int l,int r,int indx){
	if(l==r){
		if(arr[l]==1)
			arr[l]=0;
		else
			arr[l]=1;
		tree[node].ans=tree[node].left=tree[node].right=arr[l];
		return ;
	}
	int mid=(l+r)/2;
	if(indx<=mid)
		update(2*node,l,mid,indx);
	else
		update(2*node+1,mid+1,r,indx);
	if(tree[2*node].right==1&&tree[2*node+1].left==1){
		tree[node].ans=tree[2*node].ans+tree[2*node+1].ans-1;
		tree[node].left=tree[2*node].left;
		tree[node].right=tree[2*node+1].right;
	}
	else{
		tree[node].ans=tree[2*node].ans+tree[2*node+1].ans;
		tree[node].left=tree[2*node].left;
		tree[node].right=tree[2*node+1].right;	
	}
}

info query(int node,int s,int e,int l,int r){
	if(s>r||e<l){
		info tmp;
		tmp.ans=tmp.left=tmp.right=0;
		return tmp;
	}
	if(s>=l&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		info n1=query(2*node,s,mid,l,r);
		info n2=query(2*node+1,mid+1,e,l,r);
		info n3;
		if(n1.right==1&&n2.left==1){
			n3.ans=n1.ans+n2.ans-1;
			n3.left=n1.left;
			n3.right=n2.right;
		}
		else{
			n3.ans=n1.ans+n2.ans;
			n3.left=n1.left;
			n3.right=n2.right;	
		}
		return n3;
	}
}
int main()
{
	// fast;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	build(1,1,n);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int x;
			cin>>x;
			update(1,1,n,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			info ans=query(1,1,n,l,r);
			cout<<ans.ans<<endl;
		}
	}
	return 0;
}