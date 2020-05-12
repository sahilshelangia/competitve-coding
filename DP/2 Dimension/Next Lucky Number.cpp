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
		string ans="";
		bool all_three=false,need=false;
		for(int i=0;i<len;i++)
		{
			if(all_three)
			{
				ans+="3";
				continue;
			}

			if(s[i]<'3')
			{
				ans+="3";
				all_three=true;
			}
			else if(s[i]=='3')
			{
				ans+="3";
			}
			else if(s[i]<'5')
			{
				ans+="5";
				all_three=true;
			}
			else if(s[i]=='5')
			{
				ans+="5";
			}
			else
			{
				all_three=true;
				ans+="3";
				int index=-1;
				for(int j=i-1;j>=0;j--)
				{
					if(s[j]<'5')
					{
						if(s[j]<'3')
							ans[j]='3';
						else if(s[j]<'5')
							ans[j]='5';
						index=j;
						break;
					}
				}
				if(index==-1)
				{
					for(int j=i+1;j<len;j++)
						ans+="3";
					for(int j=index+1;j<len;j++)
					{
						ans[j]='3';
					}
					ans+="3";
				}
				else
				{	
					for(int j=i+1;j<len;j++)
						ans+="3";
					for(int j=index+1;j<len;j++)
					{
						ans[j]='3';
					}
				}
				break;
			}
		}

		if(all_three==false)
		for(int i=len-1;i>=0;i--)
		{
			// cout<<i<<endl;
			if(ans[i]=='3'&&s[i]<'5')
			{
				ans[i]='5';
				for(int j=i+1;j<len;j++)
					ans[j]='3';
				break;
			}
		}
		if(ans<=s)
		{
			ans="";
			for(int i=0;i<=len;i++)
				ans+="3";
		}
		cout<<ans<<endl;
	}
	return 0;
}