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
vector<int> tree[4*MAX];
int arr[MAX];
ll power(ll x,int n){
	ll res=1;
	while(n){
		if(n&1)
			res=res*x%MOD;
		n=n/2;
		x=x*x%MOD;
	}
	return res;
}
// void build(int node,int l,int r){
// 	if(l==r){
// 		int i=0,tmp=arr[l];
// 		while(tmp){
// 			tree[node][i]=tmp%2;
// 			tmp/=2;
// 			i++;
// 		}
// 	}
// 	else{
// 		int mid=(l+r)/2;
// 		build(2*node,l,mid);
// 		build(2*node+1,mid+1,r);
// 		for(int i=0;i<40;i++){
// 			tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
// 		}
// 	}
// }

// vector<int>query(int node,int s,int e,int l,int r){
// 	if(s>r||e<l){
// 		vector<int>tmp(40,0);
// 		return tmp;
// 	}
// 	else if(s>=l&&e<=r)
// 		return tree[node];
// 	else{
// 		int mid=(s+e)/2;
// 		vector<int>tmp1=query(2*node,s,mid,l,r);
// 		vector<int>tmp2=query(2*node+1,mid+1,e,l,r);

// 		vector<int> tmp3(40);
// 		for(int i=0;i<40;i++){
// 			tmp3[i]=tmp1[i]+tmp2[i];
// 		}
// 		return tmp3;
// 	}
// }

int main()
{
	fast;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	for(int i=0;i<4*MAX;i++)
		for(int j=0;j<40;j++)
			tree[i].push_back(0);

	for(int i=1;i<=n;i++){
		int j=0,tmp=arr[i];
		while(tmp){
			tree[i][j]=tmp%2;
			j++;
			tmp/=2;
		}
	}

	for(int i=2;i<=n;i++){
		for(int j=0;j<40;j++){
			tree[i][j]=tree[i][j]+tree[i-1][j];
		}
	}
	// build(1,1,n);
	// for(int i=1;i<10;i++){
	// 	for(int j=0;j<40;j++)
	// 		cout<<tree[i][j]<<" ";
	// 	cout<<endl;
	// }


	int q,two;
	cin>>q>>two;
	while(q--){
		int l,r;
		cin>>l>>r;
		ll ans=0;
		std::vector<int>freq(40);
		for(int i=0;i<40;i++){
			freq[i]=tree[r][i]-tree[l-1][i];
			ll tmp=((ll)freq[i]*(freq[i]-1)*(freq[i]-2)/6)%MOD;
			tmp=(tmp+(ll)freq[i]*(r-l+1-freq[i])*(r-l-freq[i])/2)%MOD;
			ans=(ans+tmp*power(2,i))%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}