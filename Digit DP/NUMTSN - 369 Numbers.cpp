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
std::vector<int>lower,upper;
ll dp[2][2][51][40][40][2];
void intialize(string &a,string &b){
	lower.clear();
	upper.clear();
	for(int i=0;i<a.length();i++){
		lower.pb(int(a[i]-'0'));
		upper.pb(int(b[i]-'0'));
	}
	memset(dp,-1,sizeof(dp));
}
ll countNum(int flagl,int flagr,int indx,int diff36,int diff69,int three){
	if(diff69<0||diff36<0||diff69>39||diff36>39)
		return 0;
	if(indx==lower.size())
		return diff36==diff69&&diff69==20&&three;

	ll &ans=dp[flagl][flagr][indx][diff36][diff69][three];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=0;i<=9;i++){
		if(flagl==0&&i<lower[indx]||flagr==0&&i>upper[indx])
			continue;
		int nflagl=1,nflagr=1,ndiff36=diff36,ndiff69=diff69,nthree=three;
		if(flagl==0&&i==lower[indx])
			nflagl=0;
		if(flagr==0&&i==upper[indx])
			nflagr=0;
		if(i==3){
			nthree=1;
			ndiff36++;
		}
		if(i==6){
			ndiff36--;
			ndiff69++;
		}
		if(i==9){
			ndiff69--;
		}
		ans=ans+countNum(nflagl,nflagr,indx+1,ndiff36,ndiff69,nthree);
		ans=ans%MOD;
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		while(a.length()<b.length()){
			a="0"+a;
		}
		// cout<<a<<":"<<b<<endl;
		intialize(a,b);
		// flagl,flagr,indx,3-6,6-9
		ll ans=countNum(0,0,0,20,20,0);
		cout<<ans<<endl;
	}
	return 0;
}																					