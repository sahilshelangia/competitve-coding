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
int cost[MAX],danger[MAX];
vector<int>tree[4*MAX];
void build(int node,int l,int r){
	if(l==r){
		tree[node][danger[l]]=1;
	}
	else{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		for(int i=0;i<101;i++)
			tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
	}
}

std::vector<int> query(int node,int s,int e,int l,int r){
	if(s>r||e<l){
		std::vector<int> v(101,0);
		return v;
	}
	if(s>=l&&e<=r){
		std::vector<int> v=tree[node];
		return v;
	}
	else{
		int mid=(s+e)/2;
		std::vector<int> v1=query(2*node,s,mid,l,r);
		std::vector<int> v2=query(2*node+1,mid+1,e,l,r);
		std::vector<int> v3;
		for(int i=0;i<101;i++)
			v3.push_back(v1[i]+v2[i]);
		return v3;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cost[i];
	int max_pos=1e6+5;
	int spf[max_pos];
	memset(spf,-1,sizeof(spf));
	for(int i=2;i<max_pos;i++){
		if(spf[i]==-1){
			spf[i]=i;
			for(int j=2*i;j<max_pos;j+=i){
				if(spf[j]==-1)
					spf[j]=i;
			}
		}
	}

	for(int i=1;i<=n;i++){
		int x=cost[i];
		int ans=1;
		while(x!=1){
			int prevSPF=spf[x],tmp=0;
			while(spf[x]==prevSPF){
				tmp++;
				x=x/spf[x];
			}
			ans=ans*(tmp+1);
		}
		danger[i]=ans;
	}

	int q;
	cin>>q;
	for(int i=0;i<4*MAX;i++)
		for(int j=0;j<200;j++)
			tree[i].pb(0);

	// build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<200;j++)
			tree[i][j]=tree[i-1][j];
		tree[i][danger[i]]++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int freq[200];
		for(int i=1;i<200;i++){
			freq[i]=tree[r][i]-tree[l-1][i];
		}
		int ans=0;
		for(int i=1;i<200;i++)
			ans=ans+freq[i]*(freq[i]-1)/2;
		cout<<ans<<endl;
	}
	return 0;
}