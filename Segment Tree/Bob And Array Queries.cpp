#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 500005
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
int tree[4*MAX]={0},arr[MAX]={0};
void update(int node,int l,int r,int indx,int val){
	if(l==r){
		tree[node]+=val;
		arr[l]+=val;

		tree[node]=max(0,tree[node]);
		arr[l]=max(0,arr[l]);
	}
	else {
		int mid=(l+r)/2;
		if(indx<=mid)
			update(2*node,l,mid,indx,val);
		else
			update(2*node+1,mid+1,r,indx,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

int query(int node,int s,int e,int l,int r){
	if(s>r||e<l)
		return 0;
	if(l<=s&&e<=r)
		return tree[node];
	else{
		int mid=(s+e)/2;
		return (query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r));
	}
}
int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int indx;
			cin>>indx;
			update(1,1,n,indx,1);
		}
		else if(type==2){
			int indx;
			cin>>indx;
			update(1,1,n,indx,-1);
		}
		else{
			int l,r;
			cin>>l>>r;
			int ans=query(1,1,n,l,r);
			cout<<ans<<endl;
		}
	}
	return 0;
}