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
		int n;
		cin>>n;
		int day1[n+1],day2[n+1];
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			day1[x]=day2[y]=i;
		}
		int dp[n+1][n+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i==0||j==0)
					dp[i][j]=0;
				else
				{
					if(day1[i]==day2[j])
						dp[i][j]=1+dp[i-1][j-1];
					else
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[n][n]<<endl;
	}
	return 0;
}