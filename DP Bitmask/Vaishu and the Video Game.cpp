#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
#define eps 1e-9
#define infi 1000000000000
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
ll l,n,m,val[60]={0};
ll dp[6000000];
ll count(ll a,ll b){
	int ans=0;
	while(b){
		if(b%2==1&&a%2==0)
			ans++;
		b/=2;
		a/=2;
	}
	return ans;
}

ll min_cost(ll lvl){
	if(dp[lvl]==-1){
		ll ans=infi;
		for(int i=1;i<=l;i++){
			if((val[i]&lvl)!=val[i]){
				ll x=count(lvl,val[i]);
				ans=min(ans,(ll)pow(x,m)+min_cost(val[i]|lvl));
			}
		}
		if(ans==infi)
			ans=0;
		dp[lvl]=ans;
	}
	return dp[lvl];
}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	cin>>l>>n>>m;
	for(int i=1;i<=l;i++){
		int cnt;
		cin>>cnt;
		while(cnt--){
			int x;
			cin>>x;
			val[i]=val[i]|(1<<x);
		}
		// cout<<i<<" "<<val[i]<<endl;
	}
	ll ans=min_cost(0);
	cout<<ans<<endl;
	return 0;
}