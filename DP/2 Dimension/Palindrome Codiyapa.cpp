#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 81
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
string x,y;
int dp[MAX][MAX],e1,e2,dp1[MAX][MAX],dp2[MAX][MAX],dp3[MAX][MAX][MAX][MAX];
ll cnt=0;
 
bool check_palindrome(int s1,int e1,int s2,int e2)
{
	string s;
	for(int i=s1;i<=e1;i++)
		s+=x[i];
	for(int i=s2;i<=e2;i++)
		s+=y[i];
 
	bool flag=true;
	int len=s.length();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			flag=false;
			break;
		}
	}
	return flag;
}

bool ispd1(int i1,int i2)
{
	if(i1>i2)
		return 1;
	if(dp1[i1][i2]==-1)
	{
		if(x[i1]==x[i2])
			dp1[i1][i2]=ispd1(i1+1,i2-1);
		else
			dp1[i1][i2]=0;
	}
	return dp1[i1][i2];
}

bool ispd2(int i1,int i2)
{
	if(i1>i2)
		return 1;
	if(dp2[i1][i2]==-1)
	{
		if(y[i1]==y[i2])
			dp2[i1][i2]=ispd2(i1+1,i2-1);
		else
			dp2[i1][i2]=0;
	}
	return dp2[i1][i2];
}
 
bool ispd3(int i1,int i2,int j1,int j2)
{
	if(i1>i2) return ispd2(j1,j2);
	if(j1>j2) return ispd1(i1,i2);
	if(dp3[i1][i2][j1][j2]==-1)
	{
		if(x[i1]==y[j2])
			dp3[i1][i2][j1][j2]=ispd3(i1+1,i2,j1,j2-1);
		else
			dp3[i1][i2][j1][j2]=0;
	}
	return dp3[i1][i2][j1][j2];
}
 
int min_part(int s1,int s2)
{
	// cout<<cnt<<endl;
	// cnt++;
	if(s1>e1&&s2>e2)
		return 0;
	else
	{
		if(dp[s1][s2]==-1)
		{
			int ans=1000;
			for(int i=s1;i<=e1+1;i++)
			{
				for(int j=s2;j<=e2+1;j++)
				{
					if(i==s1&&j==s2)
						continue;
					if(ispd3(s1,i-1,s2,j-1))
					{
						ans=min(ans,1+min_part(i,j));
					}
				}
			}
			dp[s1][s2]=ans;
		}
		return dp[s1][s2];
	}
}
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		e1=x.length()-1;
		e2=y.length()-1;
		memset(dp,-1,sizeof(dp));
		memset(dp1,-1,sizeof(dp1));
		memset(dp2,-1,sizeof(dp2));
		memset(dp3,-1,sizeof(dp3));
		int ans=min_part(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}