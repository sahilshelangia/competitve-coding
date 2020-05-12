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
		int m,n;
		cin>>m>>n;
		int set[n],dp[m+1]={0};
		for(int i=0;i<n;i++)
		{
			cin>>set[i];
			dp[set[i]]=1;
		}

		for(int i=1;i<=m;i++)
		{
			int ans=1;
			for(int j=0;j<n;j++)
			{
				ll x=i-set[j];
				if(x>=0)
					ans=ans&dp[x];
			}
			dp[i]=!ans;
			// cout<<dp[i]<<" ";
		}
		if(dp[m])
			cout<<"Little Deepu"<<endl;
		else
			cout<<"Kate"<<endl;
	}
	return 0;
}