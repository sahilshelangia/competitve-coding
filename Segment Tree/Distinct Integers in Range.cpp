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
int n,a[MAX],b[MAX];
bitset<5005>treea[4*MAX],treeb[4*MAX];
void build(int node,int l,int r){
	if(l==r){
		treea[node][a[l]]=treeb[node][b[l]]=1;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		treea[node]=treea[2*node]|treea[2*node+1];
		treeb[node]=treeb[2*node]|treeb[2*node+1];
	}
}

bitset<5005> querya(int node,int s,int e,int l,int r){
	if(l>e||r<s){
		bitset<5005> x;
		return x;
	}
	else if(s>=l&&e<=r)
		return treea[node];
	else{
		int mid=(s+e)/2;
		return querya(2*node,s,mid,l,r)|querya(2*node+1,mid+1,e,l,r);
	}
}

bitset<5005> queryb(int node,int s,int e,int l,int r){
	if(l>e||r<s){
		bitset<5005> x(0);
		return x;
	}
	else if(s>=l&&e<=r)
		return treeb[node];
	else{
		int mid=(s+e)/2;
		return queryb(2*node,s,mid,l,r)|queryb(2*node+1,mid+1,e,l,r);
	}
}
int main()
{
	fast;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];

	build(1,1,n);

	int q;
	cin>>q;
	while(q--){
		int la,ra,lb,rb;
		cin>>la>>ra>>lb>>rb;
		bitset<5005>ans=querya(1,1,n,la,ra)|queryb(1,1,n,lb,rb);
		cout<<ans.count()<<endl;
	}
	return 0;
}