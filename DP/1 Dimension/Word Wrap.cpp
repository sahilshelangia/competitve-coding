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
		ll n;
		cin>>n;
		ll arr[n+1],limit,cost[n+1][n+1],cumm[n+1]={0};
		for(int i=1;i<=n;i++)
			cin>>arr[i],cumm[i]=cumm[i-1]+arr[i];
		cin>>limit;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ll x=cumm[j]-cumm[i-1]+j-i;
				if(x>limit)
					x=MOD;
				cost[i][j]=x;
			}
		}

		ll ans[n+1]={0};
		for(int i=n;i>=1;i--)
		{
			ans[i]=MOD;
			for(int j=i;j<=n;j++)
			{	
				ans[i]=min(ans[i],cost[i][j]+ans[j]);
			}
		}
		cout<<ans[1]<<endl;
	}
	return 0;
}