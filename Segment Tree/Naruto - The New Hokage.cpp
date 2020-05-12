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
ll arr[MAX],tree[4*MAX][11],lazy[4*MAX]={0};
ll power(ll x,ll n){
	ll res=1;
	while(n){
		if(n&1)
			res=res*x%MOD;
		n=n/2;
		x=x*x%MOD;
	}
	return res;
}
void build(int node,int l,int r){
	if(l==r){
		for(int i=1;i<=10;i++)
			tree[node][i]=power(node,i);
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		for(int i=1;i<=10;i++)
			tree[node][i]=(tree[2*node][i]+tree[2*node+1][i])%MOD;
	}
}

void update(int node,int l,int r,int indx,int val){
	if(l==r){
		arr[l]=arr[l]+val;
		for(int i=1;i<=10;i++)
			tree[node][i]=power(node,i);
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			build(2*node,l,mid);
		else
			build(2*node+1,mid+1,r);
		for(int i=1;i<=10;i++)
			tree[node][i]=(tree[2*node][i]+tree[2*node+1][i])%MOD;
	}
}

void update_lazy(int node,int s,int e,int l,int r,int val){
	if(s>r||e<l)
		return ;

	else if(s>=l&&e<=r){
		lazy[node]+=val;
	}

	else{
		int mid=(l+r)/2;
		update_lazy(2*node,s,mid,e,l,r,val);
		update_lazy(2*node+1,mid+1,e,l,r,val);
	}
}

ll query(int node,int s,int e,int l,int r,int p){
	if(s>r||e<l)
		return 0;
	else if(s>=l&&e<=r)
		return tree[node][p];
	else{
		int mid=(s+e)/2;
		if(lazy[node]!=0){
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
			lazy[node]=0;
		}
		return (query(2*node,s,mid,l,r,p)+query(2*node+1,mid+1,e,l,r,p))%MOD;
	}

}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		build(1,1,n);

		int q;
		cin>>q;
		while(q--){
			int type;
			cin>>type;
			if(type==1){
				int indx,val;
				cin>>indx>>val;
				update(1,1,n,indx,val);
			}
			else if(type==2){
				int l,r,k;
				cin>>l>>r>>k;
				update_lazy(1,1,n,l,r,k);
			}
			else{
				int l,r,p;
				cin>>l>>r>>p;
				ll ans=query(1,1,n,l,r,p);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}