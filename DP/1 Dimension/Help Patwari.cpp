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
	ll dp[MAX]={0};
	dp[1]=1;
	dp[2]=1;
	for(int i=2;i<MAX;i++)
	{
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	int k;
	cin>>k;
	cout<<dp[k]<<endl;
	return 0;
}