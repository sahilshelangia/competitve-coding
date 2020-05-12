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
int A[MAX],D[MAX];
struct node
{
	ll sum,mini,maxi;
};
node tree[4*MAX];
void combine(int v){
	tree[v].mini=min(tree[2*v].mini,tree[2*node+1].mini);
	tree[v].maxi=max(tree[2*v].maxi,tree[2*node+1].maxi);
	tree[v].sum=tree[2*v].sum+tree[2*node+1].sum;
}

void build(int v,int l,int r){
	if(l==r){
		tree[v].mini=tree[v].maxi=tree[v].sum=A[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*v,l,mid);
		build(2*v+1,mid+1,r);
		combine(v);
	}
}

ll query(int v,int l,int r,ll x){
	if()
}
int main()
{
	fast;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	build(1,1,n);
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		ll ans=query(1,1,n,x);
		cout<<ans<<endl;
	}

	return 0;
}