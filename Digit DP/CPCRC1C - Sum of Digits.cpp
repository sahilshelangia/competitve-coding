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
vector<int>digit;
ll dp[10][2][91];
void intialize(ll x){
	memset(dp,-1,sizeof(dp));
	digit.clear();
	while(x){
		digit.pb(x%10);
		x/=10;
	}
	reverse(digit.begin(),digit.end());
}

ll digitSum(int indx,int flag,int sum){
	if(sum<0)
		return 0;
	if(indx==digit.size())
		return sum==0;
	ll &ans=dp[indx][flag][sum];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=0;i<=9;i++){
		if(flag==0&&i>digit[indx])
			break;
		int nflag;
		if(flag==0&&i==digit[indx])
			nflag=0;
		else
			nflag=1;
		ans=ans+digitSum(indx+1,nflag,sum-i);
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	while(1){
		ll a,b;
		cin>>a>>b;
		if(a==-1&&b==-1){
			break;
		}
		intialize(b);
		ll ans=0;
		for(int i=0;i<=90;i++){
			ans=ans+i*digitSum(0,0,i);
		}
		intialize(a-1);
		for(int i=0;i<=90;i++){
			ans=ans-i*digitSum(0,0,i);
		}
		// ans=ans-digitSum(0,0);
		cout<<ans<<endl;
	}
	return 0;
}