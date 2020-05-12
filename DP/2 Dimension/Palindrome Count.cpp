#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 105
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
string s;
int dp[MAX][MAX];
bool ispd(int i1,int i2)
{
	if(i1>i2)
		return 1;
	if(dp[i1][i2]==-1)
	{
		if(s[i1]==s[i2])
			dp[i1][i2]=ispd(i1+1,i2-1);
		else
			dp[i1][i2]=0;
	}
	return dp[i1][i2];
}
int main()
{
	fast;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	int len=s.length(),ans=0;
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(ispd(i,j))
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}