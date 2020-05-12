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
int a[5],b[5];
ll dp[11][11][11][11][11][5][11];

ll count(int a1,int a2,int a3,int a4,int a5,int prev,int rem)
{
	if(rem<0||a1<0||a2<0||a3<0||a4<0||a5<0)
		return 0;
	if(a1==0&&a2==0&&a3==0&&a4==0&&a5==0&&rem>=0)
		return 1;
	if(dp[a1][a2][a3][a4][a5][prev][rem]==-1)
	{
		if(prev==0)
		{
			dp[a1][a2][a3][a4][a5][prev][rem]=count(a1-1,a2,a3,a4,a5,prev,rem-1);
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2-1,a3,a4,a5,1,b[1]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3-1,a4,a5,2,b[2]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4-1,a5,3,b[3]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4,a5-1,4,b[4]-1))%MOD;
		}
		else if(prev==1)
		{
			dp[a1][a2][a3][a4][a5][prev][rem]=count(a1-1,a2,a3,a4,a5,0,b[0]-1);
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2-1,a3,a4,a5,1,rem-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3-1,a4,a5,2,b[2]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4-1,a5,3,b[3]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4,a5-1,4,b[4]-1))%MOD;
		}
		else if(prev==2)
		{
			dp[a1][a2][a3][a4][a5][prev][rem]=count(a1-1,a2,a3,a4,a5,0,b[0]-1);
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2-1,a3,a4,a5,1,b[1]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3-1,a4,a5,2,rem-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4-1,a5,3,b[3]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4,a5-1,4,b[4]-1))%MOD;
		}
		else if(prev==3)
		{
			dp[a1][a2][a3][a4][a5][prev][rem]=count(a1-1,a2,a3,a4,a5,0,b[0]-1);
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2-1,a3,a4,a5,1,b[1]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3-1,a4,a5,2,b[2]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4-1,a5,3,rem-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4,a5-1,4,b[4]-1))%MOD;
		}
		else
		{
			dp[a1][a2][a3][a4][a5][prev][rem]=count(a1-1,a2,a3,a4,a5,0,b[0]-1);
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2-1,a3,a4,a5,1,b[1]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3-1,a4,a5,2,b[2]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4-1,a5,3,b[3]-1))%MOD;
			dp[a1][a2][a3][a4][a5][prev][rem]=(dp[a1][a2][a3][a4][a5][prev][rem]+count(a1,a2,a3,a4,a5-1,4,rem-1))%MOD;
		}
	}
	return dp[a1][a2][a3][a4][a5][prev][rem];
}
int main()
{
	fast;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<5;i++)
		cin>>a[i];
	for(int j=0;j<5;j++)
		cin>>b[j];
	ll ans=count(a[0],a[1],a[2],a[3],a[4],1,b[1])%MOD;
	cout<<ans<<endl;
	return 0;
}