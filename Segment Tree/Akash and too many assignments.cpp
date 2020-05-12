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
int arr[MAX],tree[MAX][26];

void build(int node,int l,int r){
	if(l==r){
		for(int i=0;i<26;i++)
			tree[node][i]=0;
		tree[node][arr[l]]++;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		for(int i=0;i<26;i++)
			tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
	}
}

void update(int node,int l,int r,int indx,int val){
	if(l==r){
		arr[l]=val;
		for(int i=0;i<26;i++)
			tree[node][i]=0;
		tree[node][arr[l]]++;
	}
	else{
		int mid=(l+r)/2;
		if(indx<=mid)
			update(2*node,l,mid,indx,val);
		else
			update(2*node+1,mid+1,r,indx,val);
		for(int i=0;i<26;i++)
			tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
	}
}

std::vector<int>query(int node,int s,int e,int l,int r){
	if(s>r||e<l){
		std::vector<int> v(26,0);
		return v;
	}
	else if(s>=l&&e<=r){
		std::vector<int> v;
		for(int i=0;i<26;i++)
			v.pb(tree[node][i]);
		return v;
	}
	else{
		int mid=(s+e)/2;
		vector<int>v1=query(2*node,s,mid,l,r);
		vector<int>v2=query(2*node+1,mid+1,e,l,r);
		std::vector<int> v;
		for(int i=0;i<26;i++)
			v.pb(v1[i]+v2[i]);
		return v;
	}
}

int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		arr[i+1]=int(s[i]-'a');
	}

	build(1,1,n);
	while(q--){
		int type;
		cin>>type;
		if(type==0){
			int indx;
			char tmp;
			cin>>indx;
			cin>>tmp;
			// cout<<int(tmp-'a')<<endl;
			update(1,1,n,indx,int(tmp-'a'));
		}
		else{
			int l,r,k;
			cin>>l>>r>>k;
			bool flag=false;
			vector<int>freq=query(1,1,n,l,r);
			// for(int i=0;i<26;i++)
			// 	cout<<i<<" "<<freq[i]<<endl;
			for(int i=0;i<26;i++){
				if(k<=freq[i]){
					flag=true;
					char ans='a'+i;
					cout<<ans<<endl;
					break;
				}
				else{
					k=k-freq[i];
				}
			}
			if(flag==false)
				cout<<"Out of range"<<endl;
		}
	}
	return 0;
}