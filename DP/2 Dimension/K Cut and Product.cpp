#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=720720;
#define MAX 105
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
ll arr[MAX],nCr[MAX][MAX],dp[MAX][MAX];
void comb(){
	memset(nCr,0,sizeof(nCr));
	nCr[0][0]=1;
	for(int i=1;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(j==0||i==j)
				nCr[i][j]=1;
			else{
				if(j>i)
					nCr[i][j]=0;
				else
					nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
			}
		}
	}
}
ll find(int n,int k){
	if(n<0||k<0)
		return 0;
	if(n>=1&&k==0){
		ll ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*arr[i]%MOD;
		return ans;
	}
	if(dp[n][k]==-1){
		ll ans=0,prod=1;
		for(int i=n;i>1;i--){
			// cout<<i<<"==>"<<endl;
			prod=prod*arr[i]%MOD;
			ans=(ans+find(i-1,k-1)+prod*nCr[i-2][k-1]%MOD)%MOD;
			// cout<<i-1<<" "<<k-1<<"=>"<<find(i-1,k-1)<<endl;
		}
		dp[n][k]=ans;	
	}
	return dp[n][k];
}
int main()
{
	fast;
	comb();
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cin>>k;
	ll ans=find(n,k);
	cout<<ans<<endl;
	return 0;
}