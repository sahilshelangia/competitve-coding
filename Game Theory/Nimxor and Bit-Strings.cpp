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
int n;
string s;
map<int,string>mns;
map<string,int>msn;

ll power(ll x,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1)
			res=res*x%MOD;
		n=n>>1;
		x=x*x%MOD;
	}
	return res;
}
string sub(string a,string b)
{
	int na=0,nb=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='1')
			na+=pow(2,a.length()-1-i);
	}

	for(int i=0;i<b.length();i++)
	{
		if(b[i]=='1')
			nb+=pow(2,b.length()-1-i);
	}

	int res=na-nb;
	string ans;
	while(res)
	{
		ans+=char(res%2+48);
		res=res/2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

bool check(string a,string b)
{
	int na=0,nb=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='1')
			na+=pow(2,a.length()-1-i);
	}

	for(int i=0;i<b.length();i++)
	{
		if(b[i]=='1')
			nb+=pow(2,b.length()-1-i);
	}
	return na>=nb;
}


int divide(string a)
{
	string quotient;
	string remainder;
	for(int i=0;i<n;i++)
	{
		remainder=remainder+s[i];
		if(check(remainder,a))
		{
			quotient+='1';
			remainder=sub(remainder,a);
		}
		else
			quotient+='0';
	}

	ll ans=1,len=quotient.length();
	for(int i=0;i<len;i++)
	{
		if(quotient[i]=='1')
			ans=(ans+power(2,len-i-1))%MOD;
	}
	return ans;
}
int main()
{
	fast;

	mns[0]="0";
	for(int i=1;i<101;i++)
	{
		int x=i;
		string tmp;
		while(x)
		{
			tmp+=char(x%2+48);
			x=x/2;	
		}
		reverse(tmp.begin(),tmp.end());
		mns[i]=tmp;
		msn[tmp]=i;
	}

	cin>>n;
	cin>>s;
	int q;
	cin>>q;
	ll dp[105];
	for(int i=0;i<105;i++)
		dp[i]=-1;
	while(q--)
	{
		int x;
		cin>>x;
		if(dp[x]==-1)
			dp[x]=divide(mns[x]);
		cout<<dp[x]<<'\n';
	}
	return 0;
}