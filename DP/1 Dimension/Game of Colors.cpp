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
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	int freq[n+1][n+1],dp[106][n+1][n+1][3]={0};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>freq[i][j];
	//0 for red,1 for green,2 for blue
	
	for(int t=0;t<=105;t++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[t][i][j][(t/freq[i][j])%3]=1;
				dp[t][i][j][0]+=dp[t][i-1][j][0]+dp[t][i][j-1][0]-dp[t][i-1][j-1][0];
				dp[t][i][j][1]+=dp[t][i-1][j][1]+dp[t][i][j-1][1]-dp[t][i-1][j-1][1];
				dp[t][i][j][2]+=dp[t][i-1][j][2]+dp[t][i][j-1][2]-dp[t][i-1][j-1][2];
			}
		}
	}

	while(q--)
	{
		int t,x1,y1,x2,y2,c;
		cin>>t>>x1>>y1>>x2>>y2;
		char color;
		cin>>color;
		if(color=='R')
			c=0;
		else if(color=='G')
			c=1;
		else
			c=2;

		ll ans=dp[t][x2][y2][c]-dp[t][x1-1][y2][c]-dp[t][x2][y1-1][c]+dp[t][x1-1][y1-1][c];
		cout<<ans<<endl;
	}
	return 0;
}