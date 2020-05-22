#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 200005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::vector<pair<int,int> >treemn(4*MAX),treemx(4*MAX);
ll arr[MAX];
int distinctDigit(int x){
	unordered_set<int>us;
	while(x){
		us.insert(x%10);
		x/=10;
	}
	return us.size();
}
void combine(int node){
	int left=2*node,right=2*node+1;
	// tree mx
	if(treemx[left].second>treemx[right].second)
		treemx[node]=treemx[left];
	else if(treemx[right].second>treemx[left].second)
		treemx[node]=treemx[right];
	else
		treemx[node]=mp(treemx[left].first+treemx[right].first,treemx[left].second);

	// tree mn
	if(treemn[left].second<treemn[right].second)
		treemn[node]=treemn[left];
	else if(treemn[right].second<treemn[left].second)
		treemn[node]=treemn[right];
	else
		treemn[node]=mp(treemn[left].first+treemn[right].first,treemn[left].second);	
}
void build(int node,int l,int r){
	if(l==r){
		treemx[node]=mp(1,distinctDigit(arr[l]));
		treemn[node]=mp(1,distinctDigit(arr[l]));
		return ;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		combine(node);
	}
}

void update(int node,int l,int r,int indx){
	if(l==r){
		treemx[node]=mp(1,distinctDigit(arr[l]));
		treemn[node]=mp(1,distinctDigit(arr[l]));
	}
	else{
		int m=(l+r)/2;
		if(indx<=m)
			update(2*node,l,m,indx);
		else
			update(2*node+1,m+1,r,indx);
		combine(node);
	}
}

// MXQUery
pair<int,int>query1(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return mp(0,-1);
	if(st>=l&&en<=r)
		return treemx[node];
	int mid=(st+en)/2;
	pair<int,int>x1=query1(2*node,st,mid,l,r),x2=query1(2*node+1,mid+1,en,l,r);
	if(x1.second>x2.second)
		return x1;
	if(x1.second<x2.second)
		return x2;
	return mp(x1.first+x2.first,x2.second);
}

pair<int,int>query2(int node,int st,int en,int l,int r){
	if(st>r||en<l)
		return mp(0,100);
	if(st>=l&&en<=r)
		return treemn[node];
	int mid=(st+en)/2;
	pair<int,int>x1=query2(2*node,st,mid,l,r),x2=query2(2*node+1,mid+1,en,l,r);
	if(x1.second>x2.second)
		return x2;
	if(x1.second<x2.second)
		return x1;
	return mp(x1.first+x2.first,x2.second);
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		arr[i]=arr[i]%MOD;
	}
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		string type;
		cin>>type;
		ll l,r;
		cin>>l>>r;
		if(type=="ADD"){
			arr[l]=(arr[l]+r)%MOD;
			update(1,1,n,l);
		}
		else if(type=="MUL"){
			arr[l]=(arr[l]*r)%MOD;
			update(1,1,n,l);
		}
		else if(type=="REP"){
			arr[l]=r;
			update(1,1,n,l);
		}
		else if(type=="MAX"){
			pair<int,int>x=query1(1,1,n,l,r);
			cout<<x.second<<" "<<x.first<<endl;
		}
		else if(type=="MIN"){
			pair<int,int>x=query2(1,1,n,l,r);
			cout<<x.second<<" "<<x.first<<endl;	
		}
	}
	return 0;
}