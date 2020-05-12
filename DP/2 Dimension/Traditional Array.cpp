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
std::vector<int>adj[MAX];
int main()
{
	for(int i=1;i<MAX;i++)
	{
		for(int j=1;j<MAX;j++)
		{
			if(i%j==0||j%i==0)
				adj[i].push_back(j);
		}
	}

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll dp[m+1];
		for(int i=1;i<=m;i++)
			dp[i]=1;
		for(int i=2;i<=n;i++)
		{
			ll tmp[m+1]={0};
			for(int j=1;j<=m;j++)
			{
				int sz=adj[j].size();
				for(int k=0;k<sz;k++)
				{
					if(adj[j][k]<=m)
						tmp[j]=(tmp[j]+dp[adj[j][k]])%MOD;
				}
			}
			for(int j=1;j<=m;j++)
				dp[j]=tmp[j];
		}
		ll ans=0;
		for(int i=1;i<=m;i++)
			ans=(ans+dp[i])%MOD;
		cout<<ans<<endl;
	}
	return 0;
}