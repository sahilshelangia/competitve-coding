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
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int arr[n+1][m+1],nsu[n+1][m+3];;
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>arr[i][j];
				nsu[i][j]=-MAX;
			}
		}
		for(int i=0;i<=m;i++)
			nsu[0][i]=-MAX;
		for(int i=0;i<=n;i++)
			nsu[i][m+1]=nsu[i][0]=-MAX;

		nsu[0][k]=0;

		//Neeche se Upar=============
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(max3(nsu[i-1][j],nsu[i-1][j-1],nsu[i-1][j+1])>=0)
					nsu[i][j]=max3(nsu[i-1][j],nsu[i-1][j-1],nsu[i-1][j+1])+arr[i][j];
			}
		}

		// for(int i=n;i>=1;i--)
		// {
		// 	for(int j=1;j<=m;j++)
		// 		cout<<nsu[i][j]<<" ";
		// 	cout<<endl;
		// }
		
		//==========================================
		int ans=-1;
		for(int lvl=0;lvl<=n;lvl++)
		{
			int stone_removed[n+1][m+1];
			for(int i=lvl+1;i<=lvl+m;i++)
			{
				if(i>n)
					break;
				for(int j=1;j<=m;j++)
					stone_removed[i][j]=max(0,arr[i][j]);
			}
			for(int i=lvl+m+1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					stone_removed[i][j]=arr[i][j];
			}
			int dp[n+1][m+2];
			for(int i=0;i<=n;i++)
				dp[i][0]=dp[i][m+1]=-MAX;

			for(int i=0;i<=m+1;i++)
				dp[lvl][i]=nsu[lvl][i];
			for(int i=lvl+1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(max3(dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1])>=0)
						dp[i][j]=max3(dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1])+stone_removed[i][j];
					else
						dp[i][j]=-MAX;
				}
			}
			for(int i=1;i<=m;i++)
				ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}