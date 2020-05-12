// #include<bits/stdc++.h>
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define debug cout<<"here"<<endl;
// #define ll int
// #define mp make_pair
// #define pb push_back
// #define endl '\n'
// const ll MOD=1e9+7;
// #define MAX 200005
// #define eps 1e-9
// #define infi 1000000000000
// #define intial 0
// #define waiting 1
// #define visited 2
// #define nill -1
// #define PII pair<ll,ll>
// #define input freopen("input.txt","r",stdin);
// #define output freopen("output.txt","w",stdout);
// using namespace std;
// std::vector<int> digit;
// ll dp[2][10][90][90];
// void intialize(ll n){
// 	digit.clear();
// 	while(n){
// 		digit.pb(n%10);
// 		n/=10;
// 	}
// 	reverse(digit.begin(),digit.end());
// }

// ll countZip(int flag,int indx,int oddPos,int evenPos,int sz){
// 	if(oddPos<0||evenPos<0)
// 		return 0;
// 	if(indx==sz){
// 		return oddPos==0&&evenPos==0;
// 	}

// 	ll &ans=dp[flag][indx][oddPos][evenPos];
// 	if(ans!=-1)
// 		return ans;
// 	ans=0;
// 	for(int i=0;i<=9;i++){
// 		if(flag==0&&i>digit[indx])
// 			break;
// 		int nflag=1,noddPos=oddPos,nevenPos=evenPos;
// 		if(sz%2==0){
// 			if(indx%2==0)
// 				nevenPos=evenPos-i;
// 			else
// 				noddPos=oddPos-i;
// 		}
// 		else{
// 			if(indx%2==1)
// 				nevenPos=evenPos-i;
// 			else
// 				noddPos=oddPos-i;
// 		}
// 		if(flag==0&&i==digit[indx])
// 			nflag=0;
// 		ans=ans+countZip(nflag,indx+1,noddPos,nevenPos,sz);
// 	}
// 	return ans;
// }

// int main()
// {
// 	#ifndef LOCAL
// 	fast;
// 	#endif
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		ll a,b;
// 		cin>>a>>b;
// 		intialize(b);
// 		ll ans=0;
// 		for(int i=0;i<90;i++){
// 			// memset(dp,-1,sizeof(dp));
// 			// flag,indx,oddpos sum,evenpos sum,number of digits
// 			ans=ans+countZip(0,0,i,i+1,digit.size());
// 		}
// 		// return 0;

// 		a--;
// 		intialize(a);
// 		for(int i=0;i<90;i++){
// 			// memset(dp,-1,sizeof(dp));
// 			// flag,indx,oddpos sum,evenpos sum,number of digits
// 			ans=ans-countZip(0,0,i,i+1,digit.size());
// 		}
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }


#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll int
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
ll dp[2][11][200];
void intialize(ll n){
	digit.clear();
	while(n){
		digit.pb(n%10);
		n/=10;
	}
	reverse(digit.begin(),digit.end());
}

ll countZip(int flag,int indx,int diff,int sz){
	if(diff<-90)
		return 0;
	if(indx==sz){
		return diff==91;
	}

	ll &ans=dp[flag][indx][diff];
	// ll ans=0;
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=0;i<=9;i++){
		if(flag==0&&i>digit[indx])
			break;
		int nflag=1,ndiff=diff;
		if(sz%2==0){
			if(indx%2==0)
				ndiff+=i;
			else
				ndiff-=i;
		}
		else{
			if(indx%2==1)
				ndiff+=i;
			else
				ndiff-=i;
		}
		if(flag==0&&i==digit[indx])
			nflag=0;
		ans=ans+countZip(nflag,indx+1,ndiff,sz);
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
		ll a,b;
		cin>>a>>b;
		intialize(b);
		memset(dp,-1,sizeof(dp));
		ll ans=countZip(0,0,0+90,digit.size());
		// cout<<ans<<endl;
		// return 0;

		a--;
		intialize(a);
		memset(dp,-1,sizeof(dp));
		ans=ans-countZip(0,0,0+90,digit.size());
		cout<<ans<<endl;
	}
	return 0;
}