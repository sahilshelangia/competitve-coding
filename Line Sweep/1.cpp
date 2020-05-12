#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 105
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Rect{
	int x1,y1,x2,y2;
	Rect(int a,int b,int c,int d){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
	}
	Rect(){
		x1=y1=x2=y2=0;
	}
};
int arr[MAX],lazy[4*MAX];
vector< pair<int,int> >tree(4*MAX);
void combine(int node){
	int left=2*node,right=2*node+1;
	if(tree[left].first<tree[right].first)
		tree[node]=tree[left];

	else if(tree[right].first<tree[left].first)
		tree[node]=tree[right];
	
	else
		tree[node]=mp(tree[left].first,tree[left].second+tree[right].second);
}
void push(int node){
	lazy[2*node]+=lazy[node];
	lazy[2*node+1]+=lazy[node];
	tree[2*node].first+=lazy[node];
	tree[2*node+1].first+=lazy[node];
	lazy[node]=0;
}
int query(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return 0;
	if(st>=l&&en<=r){
		if(tree[node].first==0)
			return tree[node].second;
		return 0;
	}
	else{
		int mid=(st+en)/2;
		push(node);
		return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
	}
}
void update(int node,int st,int en,int l,int r,int val){
	if(st>r||en<l)
		return ;
	if(st>=l&&en<=r){
		tree[node].first+=val;
		lazy[node]+=val;
	}
	else{
		push(node);
		int mid=(st+en)/2;
		update(2*node,st,mid,l,r,val);
		update(2*node+1,mid+1,en,l,r,val);
		combine(node);
	}
}
void build(int node,int l,int r){
	if(l==r){
		tree[node]=mp(arr[l],1);
	}
	else{
		int m=(l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		combine(node);
	}
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	std::vector<Rect>v(n);
	std::vector<int>st[MAX],en[MAX];
	for(int i=0;i<n;++i){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		v[i]=Rect(x1,y1,x2,y2);
		st[x1].pb(i);
		en[x2].pb(i);
	}	
	memset(arr,0,sizeof(arr));
	memset(lazy,0,sizeof(lazy));
	build(1,1,MAX);
	ll ans=0;
	// sweep line from i=0,i<=100000
	for(int i=1;i<MAX;++i){
		for(int indx:st[i]){
			int r1=v[indx].y1,r2=v[indx].y2-1;
			update(1,1,MAX,r1,r2,+1);
			// for(int j=r1;j<=r2;++j)
			// 	arr[j]++;
		}
		// remove element 
		for(int indx:en[i]){
			int r1=v[indx].y1,r2=v[indx].y2-1;
			update(1,1,MAX,r1,r2,-1);
			// for(int j=r1;j<=r2;++j)
			// 	arr[j]--;
		}
		// for(int j=1;j<MAX;++j){
		// 	if(arr[j]>0)
		// 		ans++;
		// }
		ans=ans+MAX-query(1,1,MAX,1,MAX);
	}
	cout<<ans<<endl;
	return 0;
}