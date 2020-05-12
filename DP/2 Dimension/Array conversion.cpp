#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 20005
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
int dp[105][MAX];
int arr[105];
int n,k;

int cal(int n,int k)
{
	if(n==0)
	{
		if(k==0)
			return 1;
		else
			return 0;
	}
	if(dp[n][k]==-1)
	{
		dp[n][k]=cal(n-1,k-arr[n]);
		dp[n][k]=dp[n][k]+cal(n-1,k+arr[n]);
		dp[n][k]=dp[n][k]+cal(n-1,k-(arr[n]+n));
		dp[n][k]=dp[n][k]+cal(n-1,k-(arr[n]-n));
	}
	return dp[n][k];
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<=n;i++)
			for(int j=0;j<MAX;j++)
				dp[i][j]=-1;

		for(int i=1;i<=n;i++)
			cin>>arr[i];
		int ans=cal(n,k);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}