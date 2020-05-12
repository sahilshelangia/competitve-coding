#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 500005
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
		ll a,l,m;
		cin>>a>>l>>m;
		ll pump[m+1];
		pump[0]=0;
		for(int i=1;i<=m;i++)
			cin>>pump[i];
		sort(pump+1,pump+m+1);
		ll dp[m+1]={0};
		dp[0]=1;
		ll sum=1,left=0;
		for(int i=1;i<=m;i++)
		{
			while(left<=m&&pump[i]-pump[left]>l)
			{
				sum=sum-dp[left];
				left++;
			}
			dp[i]=(dp[i]+sum)%MOD;
			sum+=dp[i];
		}
		while(left<=m&&a-pump[left]>l)
		{
			sum=sum-dp[left];
			left++;
		}
		cout<<sum%MOD<<endl;
	}
	return 0;
}