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
		int n;
		cin>>n;
		set<string>s;
		for(int i=0;i<n;i++)
		{
			string word;
			cin>>word;
			s.insert(word);
		}
		string words;
		cin>>words;
		int len=words.length();
		int dp[len][len];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=len;i++)
		{
			// cout<<i<<":"<<endl;
			for(int j=0;j+i<=len;j++)
			{
				int left=j,right=j+i-1;
				string tmp="";
				for(int k=left;k<=right;k++)
					tmp+=words[k];
				// cout<<tmp<<endl;
				if(s.find(tmp)!=s.end())
					dp[left][right]=1;

				for(int k=left;k<right;k++)
				{
					if(dp[left][k]==1&&dp[k+1][right]==1)
					{
						dp[left][right]=1;
						break;
					}
				}
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}