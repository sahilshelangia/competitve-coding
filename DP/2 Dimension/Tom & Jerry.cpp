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
	ll n,m;
	cin>>n>>m;
	ll dp[10][10][1005];
	ll aux[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>aux[i][j];
		
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(j==k)
					continue;
				else
				{
					ll cost=0;
					for(int l=1;l<=m;l++)
					{
						if(l%2==1)
						{
							if(aux[i][l]!=j)
								cost++;
						}
						else
						{
							if(aux[i][l]!=k)
								cost++;
						}
					}
					// cout<<"row:"<<i<<" "<<j<<"-"<<k<<"="<<cost<<endl;
					ll prev=MOD;
					for(int a=0;a<10;a++)
					{
						for(int b=0;b<10;b++)
						{
							if(a==j||b==k||(a==b))
								continue;
							else
								prev=min(dp[a][b][i-1],prev);
						}
					}
					dp[j][k][i]=cost+prev;
				}
			}
		}
	}
	ll ans=MOD;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(i!=j)
				ans=min(ans,dp[i][j][n]);
		}
	}
	cout<<ans<<endl;
	return 0;
}



