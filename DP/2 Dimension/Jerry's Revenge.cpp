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
	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1],dp[n+1][m+1];
	memset(arr,0,sizeof(arr));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// cin>>arr[i][j];
			if(arr[i][j]==0)
				dp[i][j]=1+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}

	int r1=0,r2=0,c1=0,c2=0 ,maxZero=-10000000;
	for(int l=1;l<=min(n,m);l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int ii=i+l-1,jj=j+l-1;
				if(ii>n||jj>m)
					break;
				else
				{
					int tmp=2*(dp[ii][jj]-dp[i-1][jj]-dp[ii][j-1]+dp[i-1][j-1])-l*l;
					if(tmp>maxZero)
					{
						// cout<<"len: "<<l<<endl;
						r1=i;
						r2=ii;
						c1=j;
						c2=jj;
						maxZero=tmp;
					}
				}
			}
		}
	}

	// cout<<"Ans "<<r1<<" "<<r2<<" "<<" "<<c1<<" "<<c2<<endl;
	for(int i=r1;i<=r2;i++)
	{
		for(int j=c1;j<=c2;j++)
		{
			if(arr[i][j])
				arr[i][j]=0;
			else
				arr[i][j]=1;
		}
	}

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(arr[i][j])
				ans++;
	}
	cout<<ans<<endl;
	return 0;
}