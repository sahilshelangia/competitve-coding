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

bool check(string s)
{
	bool ans=true;
	int len=s.length();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			ans=false;
			break;
		}
	}
	return ans;
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int len=s.length();
		int dp[len+1][len+1]={0};
		for(int l=1;l<=len;l++)
		{
			for(int i=0;i<=len-l;i++)
			{
				int left=i,right=i+l-1;
				if(check(s.substr(left,l)))
					dp[left][right]=0;
				else
				{
					dp[left][right]=MAX;
					for(int j=left;j<right;j++)
					{
						dp[left][right]=min(dp[left][right],dp[left][j]+dp[j+1][right]+1);
					}
				}
			}
		}
		// for(int i=0;i<len;i++)
		// {
		// 	for(int j=0;j<len;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}