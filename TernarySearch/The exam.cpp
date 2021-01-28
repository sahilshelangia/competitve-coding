/*
  Author: Sahil Yadav, IIITM Gwalior
*/
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAX 200005
#define endl '\n'
const ll MOD=1e9+7;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bool check(ll a,ll b, ll x){
	// b--;
	ll p=1;
	if(a==1){
		if(x>=1)
			return true;
		return false;
	}
	for(int i=0;i<b;++i){
		p=p*a;
		if(p>x&&i!=b-1)
			return false;
	}
	return true;
}
int main()
{
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#endif
	int t;
	cin>>t;
	while(t--){
		ll x,l,n;
		cin>>x>>l>>n;
		ll low=0,high=n,ans=-1;
		while(low<=high){
			ll m=(low+high)/2;
			ll rem=n-m;
			if(check(rem,x,l)){
				ans=m;
				high=m-1;
			}
			else
				low=m+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}