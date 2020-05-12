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

int dp[20][20];
bool check(int x,int y)
{
	return x>0&&x<=15&&y>0&&y<=15;
}

int mex(set<int>s)
{
	int m=0;
	while(s.find(m)!=s.end())
		m++;
	return m;
}

int grundy(int x,int y)
{
	if(dp[x][y]==-1)
	{
		set<int>s;
		if(check(x-2,y+1))
			s.insert(grundy(x-2,y+1));
		if(check(x-2,y-1))
			s.insert(grundy(x-2,y-1));
		if(check(x+1,y-2))
			s.insert(grundy(x+1,y-2));
		if(check(x-1,y-2))
			s.insert(grundy(x-1,y-2));
		dp[x][y]=mex(s);
	}
	return dp[x][y];
}
int main()
{
	fast;
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		int k;
		cin>>k;
		int ans=0;
		for(int i=0;i<k;i++)
		{
			int x,y;
			cin>>x>>y;
			ans=ans^grundy(x,y);
		}
		if(ans)
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;
	}
	return 0;
}