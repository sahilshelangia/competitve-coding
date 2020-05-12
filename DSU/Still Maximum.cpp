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

int par[MAX],size[MAX],mini[MAX],maxi[MAX],val[MAX];
void intialize(int n)
{
	for(int i=1;i<n;i++)
		par[i]=i,size[i]=1,mini[i]=maxi[i]=val[i];
}

int root(int i)
{
	while(i!=par[i])
	{
		par[i]=par[par[i]];
		i=par[i];
	}
	return i;
}

int weighted_union(int u,int v)
{
	int rootu=root(u);
	int rootv=root(v);
	if(rootu==rootv)
		return 0;
	if(size[rootu]<size[rootv])
	{
		mini[rootv]=min(mini[rootv],mini[rootu]);
		maxi[rootv]=max(maxi[rootv],maxi[rootu]);
		par[rootu]=rootv;
		size[rootv]+=size[rootu];
	}
	else
	{
		mini[rootu]=min(mini[rootu],mini[rootv]);
		maxi[rootu]=max(maxi[rootu],maxi[rootv]);
		par[rootv]=rootu;
		size[rootu]+=size[rootv];
	}
}

int main()
{
	fast;
	int n;
	cin>>n;
	int edge[n+1][2],ans[n+1];
	for(int i=1;i<n;i++)
		cin>>edge[i][0]>>edge[i][1];
	for(int i=1;i<=n;i++)
		cin>>val[i];
	intialize(n+1);

	int query[n];
	for(int i=1;i<n;i++)
		cin>>query[i];

	ans[n-1]=0;
	for(int i=n-1;i>1;i--)
	{
		int u=edge[query[i]][0],v=edge[query[i]][1];
		weighted_union(u,v);
		ans[i-1]=max(ans[i],abs(mini[root(u)]-maxi[root(u)]));
	}
	for(int i=1;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}