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
std::vector<int>adj;
ll dp[MAX][105];
ll count(int rem,int k){
	if(rem==-1){
		if(k==0)
			return 1;
		else
			return 0;
	}
	if(k==0)
		return 1;
	if(dp[rem][k]==-1)
		dp[rem][k]=(count(rem-1,k-1)*adj[rem]+count(rem-1,k))%MOD;
	return dp[rem][k];
}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;
	int freq[MAX]={0};
	freq[0]=1;
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		freq[x]++;
	}	
	for(int i=0;i<MAX;i++){
		if(freq[i])
			adj.pb(freq[i]);
	}
	sort(adj.begin(),adj.end());
	n=adj.size();
	// for(int i=0;i<n;i++)
	// 	cout<<adj[i]<<" ";

	ll ans=count(n-1,k);
	cout<<ans<<endl;

	return 0;
}