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
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int dp[MAX]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10000;j++)
		{
			ll x=arr[i]*j%360;
			dp[x]=1;
		}
	}
	while(k--)
	{
		ll x;
		cin>>x;
		if(dp[x])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


	return 0;
}