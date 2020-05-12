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
		ll ans[3]={0},final=0;
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			int x=int(s[i]-'0');
			int y=x;
			x=x%3;
			ll a,b,c;
			if(x==0)
			{
				a=(2*ans[0]+1)%MOD;
				b=(2*ans[1])%MOD;
				c=(2*ans[2])%MOD;
				if(y%2==0)
					final=(final+ans[0]+1)%MOD;
			}
			else if(x==1)
			{
				a=(ans[0]+ans[2])%MOD;
				b=(ans[1]+ans[0]+1)%MOD;
				c=(ans[2]+ans[1])%MOD;
				if(y%2==0)
					final=(final+ans[2])%MOD;
			}
			else if(x==2)
			{
				a=(ans[0]+ans[1])%MOD;
				b=(ans[1]+ans[2])%MOD;
				c=(ans[2]+ans[0]+1)%MOD;
				if(y%2==0)
					final=(final+ans[1])%MOD;
			}
			ans[0]=a,ans[1]=b,ans[2]=c;
		}
		cout<<final<<endl;
	}
	return 0;
}