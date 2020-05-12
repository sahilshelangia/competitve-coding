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
int m,d;
ll dp[2][2][2005][2005];
string a,b;
ll ways(int flagl,int flagu,int indx,int rem){
	if(indx==b.length())
		return rem==0;

	ll &ans=dp[flagl][flagu][indx][rem];
	if(ans!=-1)
		return ans;
	ans=0;
	int low=a[indx]-'0',high=b[indx]-'0';
	if(indx%2){
		// we have to put only d here
		if(flagl==0&&d<low||flagu==0&&d>high)
			return 0;
		int nflagl,nflagu;
		if(flagl==0&&d==low)
			nflagl=0;
		else
			nflagl=1;

		if(flagu==0&&d==high)
			nflagu=0;
		else
			nflagu=1;
		
		ans=ways(nflagl,nflagu,indx+1,(rem*10+d)%m)%MOD;
		return ans;
	}

	for(int i=0;i<=9;i++){
		if(flagl==0&&i<low||flagu==0&&i>high||i==d)
			continue;

		int nflagl,nflagu;
		if(flagl==0&&i==low)
			nflagl=0;
		else
			nflagl=1;

		if(flagu==0&&i==high)
			nflagu=0;
		else
			nflagu=1;
	
		ans=(ans+ways(nflagl,nflagu,indx+1,(rem*10+i)%m))%MOD;
	}
	return ans;
}
int main()
{
	#ifndef LOCA
	fast;
	#endif
	memset(dp,-1,sizeof(dp));
	cin>>m>>d;
	cin>>a>>b;
	cout<<ways(0,0,0,0)<<endl;
	return 0;
}