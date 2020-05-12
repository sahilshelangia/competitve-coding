#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 105
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

ll dp[MAX][MAX];
int main()
{
	fast;
	int n;
	cin>>n;
	int arr[n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		cin>>arr[i];

	// first max ending
	// seconf gcd
	for(int k=0;k<n;k++)
	{
		dp[arr[k]][arr[k]]++;
		for(int i=1;i<MAX;i++)
		{
			for(int j=1;j<MAX;j++)
			{
				if(i<arr[k])
				{
					dp[arr[k]][__gcd(arr[k],j)]=(dp[arr[k]][__gcd(arr[k],j)]+dp[i][j])%MOD;
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<MAX;i++)
		ans=(ans+dp[i][1])%MOD;

	cout<<ans<<endl;
	return 0;
}