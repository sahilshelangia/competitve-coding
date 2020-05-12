#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
const ll MOD=1e9+7;
#define MAX 200005
#define eps 1e-9
#define infi 1000000000000
#define intial 0
#define waiting 1
#define visited 2
#define nill -1
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;

std::vector<int> digits;
void intialize(ll n){
	digits.clear();
	while(n){
		digits.pb(n%10);
		n/=10;
	}
	reverse(digits.begin(),digits.end());
}

ll count(int flag,int indx,int freq,int d)
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		l--;
		intialize(r);
		ll ans=count(0,0,0)
	}
	return 0;
}