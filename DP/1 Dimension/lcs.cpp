#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
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
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int la,lb;
		cin>>la>>lb;
		string sa,sb;
		cin>>sa>>sb;
		sa="#"+sa;
		sb="#"+sb;
		ll dp[la+1][lb+1]={0};
		for(int i=0;i<=la;i++)
			for(int j=0;j<=lb;j++)
				dp[i][j]=0;
		for(int i=1;i<=la;i++)
			for(int j=1;j<=lb;j++)
				dp[i][j]=(sa[i]==sb[j])?(dp[i-1][j-1]+1):(max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1])));
		cout<<dp[la][lb]<<endl;
	}
	return 0;
}