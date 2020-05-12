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
		int p,q;
		cin>>p>>q;
		string sp,sq;
		cin>>sp>>sq;
		ll dp[p+1][q+1];
		for(int i=0;i<=p;i++)
		{
			for(int j=0;j<=q;j++)
			{
				if(i==0)
					dp[i][j]=j;
				else if(j==0)
					dp[i][j]=i;
				else 
					dp[i][j]=0;

			}
		}
		sp="#"+sp;
		sq="#"+sq;
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=q;j++)
			{
				if(sp[i]==sq[j])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
			}
		}
		cout<<dp[p][q]<<endl;
	}
	return 0;
}