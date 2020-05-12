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
int lis[20];
// flag, flag,indx, ending digit
int dp[2][2][15][10];
std::vector<int>lower,upper;
int digit(ll a){
	int ans=0;
	while(a){
		ans++;
		a/=10;
	}
	return ans;
}
ll power(ll x,ll n){
	ll res=1;
	for(int i=1;i<=n;i++)
		res=res*10;
	return res;
}

std::vector<PII>sameDigit(ll a,ll b){
	std::vector<PII> v;
	while(1){
		ll digA=digit(a),digB=digit(b);
		if(digA==digB){
			v.pb(mp(a,b));
			break;
		}
		else{
			v.pb(mp(a,power(10,digA)-1));
			a=power(10,digA);
		}
	}
	return v;
}

void putInVector(ll a,ll b){
	lower.clear();
	upper.clear();
	while(a){
		lower.pb(a%10);
		a/=10;
	}
	reverse(lower.begin(),lower.end());
	while(b){
		upper.pb(b%10);
		b/=10;
	}
	reverse(upper.begin(),upper.end());
	memset(dp,-1,sizeof(dp));
}

ll lids(int flagL,int flagU,int indx,int sz,int lastDigit){
	if(indx==sz){
		// cout<<endl;
		return 0;
		// base case
	}
	// if(dp[flagL][flagU][indx][lastDigit]!=-1)
	// 	return dp[flagL][flagU][indx][lastDigit];
	ll ans=0;
	int low=lower[indx],high=upper[indx];
	for(int i=0;i<=9;i++){
		if(flagL==0&&i<low||flagU==0&&i>high)
			continue;
		int nflagL,nflagU;
		if(flagL==0&&i==low)
			nflagL=0;
		else
			nflagL=1;

		if(flagU==0&&i==high)
			nflagU=0;
		else
			nflagU=1;
		// cout<<i;
		if(lastDigit<i){
			ans=max(ans,1+lids(nflagL,nflagU,indx+1,sz,i));
			cout<<ans<<"yeah"<<endl;
			lis[ans]++;
			cout<<lis[ans]<<"arjan";
		}
		
		ans=max(ans,lids(nflagL,nflagU,indx+1,sz,i));
		cout<<ans<<"yeah"<<endl;
		lis[ans]++;
	
	}
	dp[flagL][flagU][indx][lastDigit]=ans;
	return ans;

}
int main()
{
	
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		ll a,b;
		cin>>a>>b;
		for(int i=0;i<20;i++)
			lis[i]=0;
		std::vector<PII> v=sameDigit(a,b);
		for(int i=0;i<v.size();i++){
			// cout<<v[i].first<<" "<<v[i].second<<endl;
			putInVector(v[i].first,v[i].second);
			ll x=lids(0,0,0,lower.size(),0);
			cout<<endl<<x<<endl;
		}
		int ans=-1;
		for(int i=0;i<20;i++){
			if(lis[i]!=0){
				ans=i;
			}
		}
		cout<<"Case "<<test<<": ";
		cout<<ans<<" "<<lis[ans]<<endl;
		
	}
	return 0;
}