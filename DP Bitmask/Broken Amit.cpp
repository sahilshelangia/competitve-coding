#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000005
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
ll L[20],D[20],dp[MAX];

ll love(ll mask){
	ll cost=0;
	for(int i=0;i<n;i++){
		if(mask&(1<<i))
			cost+=L[i]-i*D[i];
		else
			cost+=L[i];
	}
	return cost;
}
ll gross_love(ll mask){
	if(__builtin_popcount(mask)==n)
		return 0;
	if(dp[mask]==-1){
		ll cost=0,prev=love(mask);
		for(int i=0;i<n;i++){
			if((mask&((ll)1<<i))==0){
				cost=max(cost,gross_love(mask|(1<<i))+prev);
			}
		}
		dp[mask]=cost;
	}
	return dp[mask];
}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>L[i];
	for(int i=0;i<n;i++)
		cin>>D[i];
	ll ans=gross_love(0);
	cout<<ans<<endl;
	return 0;
}