#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000005
#define eps 1e-9
#define infi 1000000
#define intial 0
#define waiting 1
#define visited 2
#define nill -1
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
 

string choc;
ll dp[MAX];
ll cal(int n)
{
	if(n<2)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	if((choc[n]!=choc[n-1])||(choc[n]!=choc[n-2])||(choc[n-2]!=choc[n-1]))
		dp[n]=3+cal(n-3);
	else
		dp[n]=0;
	return dp[n];
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>choc;
		memset(dp,-1,sizeof(dp));
		int len=choc.length();
		ll ans=0;
		for(int i=0;i<len;i++)
			ans=max(ans,cal(i));
		cout<<len-ans<<endl;
	}
	return 0;
}