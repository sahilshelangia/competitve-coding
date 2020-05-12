#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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
ll dp[MAX][MAX],arr[MAX],n;

ll max_sum(int l,int r)
{
	if(l>r)
		return 0;
	if(l==r)
		return arr[l];
	if(dp[l][r]==-1)
	{
		dp[l][r]=max(dp[l][r],arr[l]+max_sum(l+1,r));
		dp[l][r]=max(dp[l][r],arr[l]*arr[l+1]+max_sum(l+2,r));
		dp[l][r]=max(dp[l][r],arr[r]*arr[r-1]+max_sum(l,r-2));
		dp[l][r]=max(dp[l][r],arr[r]+max_sum(l,r-1));
	}
	return dp[l][r];
}
int main()
{
	fast;	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	ll ans=max_sum(1,n);
	cout<<ans<<endl;

	return 0;
}