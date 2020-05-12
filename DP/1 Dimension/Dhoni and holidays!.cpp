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

int n,arr[MAX];
ll dp[MAX][3];
int rest_min(int n,int prev)
{
	//0 for rest,
	//1 for drive,

	//2 for academy,
	if(n<0)
		return 0;
	if(dp[n][prev]==-1){
		int x=arr[n],ans=MAX;
		ans=min(ans,1+rest_min(n-1,0));
		if(x==1&&prev!=2)
		{
			ans=min(ans,rest_min(n-1,2));
		}
		else if(x==2&&prev!=1)
		{
			ans=min(ans,rest_min(n-1,1));
		}
		else if(x==3)
		{
			if(prev!=1)
				ans=min(ans,rest_min(n-1,1));
			if(prev!=2)
				ans=min(ans,rest_min(n-1,2));
		}
		dp[n][prev]=ans;
	}
	
	return dp[n][prev];
}
int main()
{
	fast;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll ans=rest_min(n-1,0);
	cout<<ans<<endl;
	return 0;
}