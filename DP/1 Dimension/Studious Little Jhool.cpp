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
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int dp[MAX];

int count(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	int x=count(n-12),y=count(n-10);
	if(x!=0&&y!=0)
		return 1+min(x,y);
	if(x!=0)
		return 1+x;
	if(y!=0)
		return 1+y;
	else return 0;
}
int main()
{
	fast;
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		int n;
		cin>>n;
		int ans=count(n);
		ans--;
		cout<<ans<<endl;
	}
	return 0;
}