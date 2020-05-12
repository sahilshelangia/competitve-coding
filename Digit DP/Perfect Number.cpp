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
std::vector<int> digit;
ll counts(int indx,int flag,int sum){
	if(sum<0)
		return 0;
	if(indx==digit.size()){
		return sum==0;
	}
	ll ans=0;
	for(int i=0;i<=9;i++){
		if(flag==0&&i>digit[indx])
			break;
		int nflag=1,nsum=sum;
		if(flag==0&&i==digit[indx])
			nflag=0;
		nsum=sum-i;
		ans=ans+counts(indx+1,nflag,nsum);
	}
	return ans;
}
ll solve(ll n){
	digit.clear();
	while(n){
		digit.pb(n%10);
		n/=10;
	}
	reverse(digit.begin(),digit.end());
	// indx,flag,sum
	ll ans=counts(0,0,10);
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	ll k;
	cin>>k;
	ll low=10,high=1e8,ans;
	while(low<=high){
		ll mid=(low+high)/2;
		if(solve(mid)>=k){
			ans=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}