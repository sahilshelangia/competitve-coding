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
	int m,p;
	cin>>m>>p;
	ll pack[p+1],cumm[p+1]={0};
	for(int i=1;i<=p;i++)
	{
		cin>>pack[i];
		cumm[i]=cumm[i-1]+pack[i];
	}

	ll dp[m+1][p+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=p;j++)
		{
			if(i==1)
				dp[i][j]=cumm[p]-cumm[j-1];
			else
			{
				ll ans=cumm[p];
				for(int k=j;k<=p;k++)
				{
					ans=min(ans,max(cumm[k]-cumm[j-1],dp[i-1][k+1]));
				}
				dp[i][j]=ans;
			}
		}
	}
	// for(int i=0;i<=m;i++)
	// {
	// 	for(int j=0;j<=p;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<dp[m][1]<<endl;
	return 0;
}