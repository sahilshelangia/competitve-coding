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
		tree[node]=arr[l];
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		tree[node]=__gcd(tree[2*node],tree[2*node+1]);
	}
}

int query(int node,int s,int e,int l,int r){
	if(s>r||e<l)
		return 0;
	if(s>=l&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		return __gcd(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
	}
}

ll fib(ll n){
	if(n<3)
		return 1;
	ll x[2][2]={{1,1},{1,0}},res[2][2]={{1,0},{0,1}};
	n=n-2;
	while(n){
		if(n&1){
			ll tmp[2][2];
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					tmp[i][j]=0;
					for(int k=0;k<2;k++){
						tmp[i][j]=(tmp[i][j]+res[i][k]*x[k][j])%MOD;
					}
				}
			}
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					res[i][j]=tmp[i][j];
		}
		ll tmp[2][2];
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				tmp[i][j]=0;
				for(int k=0;k<2;k++){
					tmp[i][j]=(tmp[i][j]+x[i][k]*x[k][j])%MOD;
				}
			}
		}
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				x[i][j]=tmp[i][j];
		n/=2;
	}
	return (res[0][0]+res[0][1])%MOD;

}
int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		int tmp=query(1,1,n,l,r);
		cout<<fib(tmp)<<endl;
	}
	return 0;
}