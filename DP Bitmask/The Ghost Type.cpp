#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 6000005
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
int n;
ll dp[MAX];

ll count(ll mask){
	if(__builtin_popcount(mask)==n)
		return 1;

	if(dp[mask]==-1){
		bool flag=true;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if((mask&(1<<i))==0){
				for(int j=1;j<=n;j++){
					if(mask&(1<<j)){
						if((i&j)==i)
							flag=false;
					}
				}
				if(flag)
					ans+=count(mask|(1<<i));
			}
		}
		if(flag==false)
			ans=0;
		dp[mask]=ans;
	}
	return dp[mask];
}
int main()
{
	fast;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	ll ans=count(0);
	cout<<ans<<endl; 
	return 0;
}