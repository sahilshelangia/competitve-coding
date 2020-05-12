#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 600005
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
int arr[MAX];
std::vector<int> tree[4*MAX];

void build(int node,int l,int r){
	if(l==r){
		tree[node].pb(arr[l]);
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		int len1=tree[2*node].size(),len2=tree[2*node+1].size();
		int i=0,j=0;
		while(i<len1&&j<len2){
			if(tree[2*node][i]<=tree[2*node+1][j]){
				tree[node].pb(tree[2*node][i]);
				i++;
			}
			else{
				tree[node].pb(tree[2*node+1][j]);
				j++;	
			}
		}
		while(i<len1){
			tree[node].pb(tree[2*node][i]);
			i++;	
		}
		while(j<len2){
			tree[node].pb(tree[2*node+1][j]);
			j++;	
		}
	}
}

int ans2(int node,int s,int e,int l,int r,int k){
	if(e<l||s>r)
		return 0;
	if(s>=l&&e<=r){
		int cnt=lower_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin();
		return cnt;		
	}
	else{
		int mid=(s+e)/2;
		return ans2(2*node,s,mid,l,r,k)+ans2(2*node+1,mid+1,e,l,r,k);
	}
}

int ans3(int node,int s,int e,int l,int r,int k){
	if(e<l||s>r)
		return 0;
	if(s>=l&&e<=r){
		int cnt=upper_bound(tree[node].begin(),tree[node].end(),k)-lower_bound(tree[node].begin(),tree[node].end(),k);
		return cnt;		
	}
	else{
		int mid=(s+e)/2;
		return ans3(2*node,s,mid,l,r,k)+ans3(2*node+1,mid+1,e,l,r,k);
	}
}

int ans4(int node,int s,int e,int l,int r,int k){
	if(e<l||s>r)
		return 0;
	if(s>=l&&e<=r){
		int cnt=tree[node].end()-upper_bound(tree[node].begin(),tree[node].end(),k);
		return cnt;		
	}
	else{
		int mid=(s+e)/2;
		return ans4(2*node,s,mid,l,r,k)+ans4(2*node+1,mid+1,e,l,r,k);
	}
}

int main()
{
	fast;
	int q;
	cin>>q;
	int n=0;
	int query[MAX][4],sz=0;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int k;
			cin>>k;
			n++;
			arr[n]=k;
		}
		else{
			int l,r,k;
			cin>>l>>r>>k;
			query[sz][0]=l,query[sz][1]=r,query[sz][2]=k,query[sz][3]=type;
			sz++;
		}
	}
	build(1,1,n);
	for(int i=0;i<sz;i++){
		if(query[i][3]==2)
			cout<<ans2(1,1,n,query[i][0],query[i][1],query[i][2])<<"\n";
		else if(query[i][3]==3)
			cout<<ans3(1,1,n,query[i][0],query[i][1],query[i][2])<<"\n";
		else
			cout<<ans4(1,1,n,query[i][0],query[i][1],query[i][2])<<"\n";
	}
	return 0;
}