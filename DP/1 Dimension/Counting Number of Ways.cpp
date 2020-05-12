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
int main()
{
	ll dp[102][MAX];
	memset(dp,0,sizeof(dp));
	for(int k=1;k<=100;k++)
	{
		ll win_sum=0,left=1,right=0;
		for(int x=1;x<MAX;x++)
		{
			dp[k][x]=win_sum;
			if(x<=k)
				dp[k][x]++;

			right++;
			win_sum=(win_sum+dp[k][right])%MOD;
			
			if(x>k)
			{
				win_sum=(win_sum-dp[k][left]+MOD)%MOD;
				left++;
			}
		}
	}

	// for(int i=0;i<4;i++)
	// {
	// 	for(int j=0;j<7;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }

	// return 0;

	int t;
	cin>>t;
	while(t--)
	{
		int x,k;
		cin>>x>>k;
		cout<<dp[k][x]<<"\n";
	}
	return 0;
}