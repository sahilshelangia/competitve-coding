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

int cal(string s)
{
	int n=s.length(),zero=0,one=0;
	map<int,int>m;
	m[one-zero]=-1;
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
			zero++;
		else
			one++;
		int x=one-zero;
		if(m.find(x)==m.end())
			m[x]=i;
		else
		{
			ans=max(ans,i-m[x]);
		}
	}
	return ans;
}
int main()
{
	fast;
	int n,ans=-1;
	cin>>n;
	string s;
	cin>>s;
	int cntx=0;
	vector<int>index;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='x')
		{
			cntx++;
			index.pb(i);
		}
	}
	int mask=1<<cntx;
	for(int k=0;k<mask;k++)
	{
		string tmp=s;
		int nn=index.size();
		for(int i=0;i<nn;i++)
		{
			if(k&(1<<i))
				tmp[index[i]]='1';
			else
				tmp[index[i]]='0';		
		}
		// cout<<tmp<<endl;
		ans=max(ans,cal(tmp));
	}
	cout<<ans<<'\n';
	return 0;
}