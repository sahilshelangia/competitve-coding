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

int primeMask[60]={0},arr[60];
int dp[60][100000];
vector<int>prime;
bool checkPrime(int x){
	for(int i=2;i<x;i++){
		if(x%i==0)
			return false;
	}
	return true;
}

int maxSubset(int n,int mask){
	if(n<=0)
		return 0;
	if(dp[n][mask]==-1){
		int ans=0;
		if((mask&primeMask[arr[n]])==0)
			ans=max(ans,maxSubset(n-1,mask|primeMask[arr[n]])+1);
		ans=max(ans,maxSubset(n-1,mask));
		dp[n][mask]=ans;	
	}
	return dp[n][mask];
}
int main()
{
	fast;
	for(int i=2;i<60;i++){
		if(checkPrime(i))
			prime.pb(i);
	}
	for(int i=2;i<60;i++){
		int mask=0;
		for(int j=0;j<prime.size();j++){
			if(i%prime[j]==0)
				mask=mask|(1<<j);
		}
		primeMask[i]=mask;
	}
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		int ans=maxSubset(n,0);
		cout<<ans<<endl;
	}
	return 0;
}