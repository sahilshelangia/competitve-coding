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
struct info
{
	ll odd,even;
};

ll arr[MAX];
info tree[4*MAX];
void build(int node,int l,int r){
	if(l==r){
		tree[node].odd=-1,tree[node].even=-1;
		if(arr[l]%2==0)
			tree[node].even=arr[l];
		else
			tree[node].odd=arr[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node].odd=max(tree[2*node].odd,tree[2*node+1].odd);
		tree[node].even=max(tree[2*node].even,tree[2*node+1].even);
	}
}

void update(int node,int l,int r,int indx,ll val){
	if(l==r){
		arr[indx]=val;
		tree[node].odd=-1,tree[node].even=-1;
		if(arr[l]%2==0)
			tree[node].even=arr[l];
		else
			tree[node].odd=arr[l];
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			build(2*node,l,mid);
		else
			build(2*node+1,mid+1,r);
		tree[node].odd=max(tree[2*node].odd,tree[2*node+1].odd);
		tree[node].even=max(tree[2*node].even,tree[2*node+1].even);
	}
}

ll query(int node,int s,int e,int l,int r,int type){
	if(s>r||e<l)
		return -1;
	else if(s>=l&&e<=r){
		if(type==2)
			return tree[node].even;
		else
			return tree[node].odd;
	}
	else {
		int mid=(s+e)/2;
		return max(query(2*node,s,mid,l,r,type),query(2*node+1,mid+1,e,l,r,type));
	}
}
int main()
{
	int n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	build(1,1,n);
	while(q--){
		int type;
		scanf("%d",&type);
		if(type==1){
			ll indx,val;
			scanf("%lld%lld",&indx,&val);
			update(1,1,n,indx,val);
		}
		else{
			int l,r;
			scanf("%lld%lld",&l,&r);
			ll ans=query(1,1,n,l,r,type);
			if(ans==-1)
				cout<<"DNE"<<'\n';
			else
				cout<<ans<<'\n';
		}
	}
	return 0;
}