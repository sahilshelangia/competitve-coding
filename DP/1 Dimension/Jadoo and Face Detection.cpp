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
	int r,c;
	cin>>r>>c;
	int arr[r+1][c+1];
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			cin>>arr[i][j];
	}	

	ll dp[r+1][c+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			dp[i][j]=arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	// cout<<dp[r][c]<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll ans=dp[x2+1][y2+1]-dp[x1+1-1][y2+1]-dp[x2+1][y1+1-1]+dp[x1+1-1][y1+1-1];
		cout<<ans<<endl;
	}
	return 0;
}