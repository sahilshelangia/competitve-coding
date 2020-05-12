#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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

ll dp[MAX];

ll cal_mex(set<ll>s)
{
	int mex=0;
	while(s.find(mex)!=s.end())
		mex++;
	return mex;
}
ll grundy(int n)
{
	if(n<=1)
		return 0;
	else if(dp[n]==-1)
	{
		set<ll>s;
		s.insert(grundy(n-2));
		s.insert(grundy(n-3));
		s.insert(grundy(n-5));

		ll ans=cal_mex(s);
		dp[n]=ans;
	}
	return dp[n];

}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=grundy(n);
		if(ans)
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;
	}
	return 0;
}