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
ll f(ll x){
	ll ans=2*x*x-12*x+7;
	return ans;
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
		int l,r;
		cin>>l>>r;
		while(r-l>3){
			int m1=l+(r-l)/3,m2=r-(r-l)/3;
			if(f(m1)<f(m2))
				r=m2;
			else
				l=m1;
		}
		ll ans=1e16;
		while(l<=r){
			ans=min(ans,f(l));
			++l;
		}
		cout<<ans<<endl;
	}
	return 0;
}