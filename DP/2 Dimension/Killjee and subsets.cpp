#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1025
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

ll power(ll x,ll n){
	ll res=1;
	while(n){
		if(n&1)
			res=res*x%MOD;
		n=n/2;
		x=x*x%MOD;
	}
	return res;
}
int main()
{
	fast;
	int n;
	cin>>n;
	int arr[n+1],max_ele=0;
	for(int i=1;i<=n;i++)
		cin>>arr[i],max_ele=max(max_ele,arr[i]);
	ll dp[n+1][MAX];
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<MAX;j++){
			if(dp[i-1][j]!=-1&&dp[i-1][j^arr[i]]!=-1)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j^arr[i]]+1);
			else if(dp[i-1][j]!=-1)
				dp[i][j]=dp[i-1][j];
			else if(dp[i-1][j^arr[i]]!=-1)
				dp[i][j]=dp[i-1][j^arr[i]]+1;
			dp[i][j]=dp[i][j]%MOD;
		}
	}

	ll ans=0;
	for(int i=0;i<=max_ele;i++){
		ans=(ans+dp[n][i]*power(31,i))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}