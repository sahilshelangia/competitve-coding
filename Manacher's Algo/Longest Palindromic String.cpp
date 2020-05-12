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
	string s,updated_str;
	cin>>s;
	updated_str="@";
	for(int i=0;i<s.length();i++)
		updated_str+="#"+s.substr(i,1);
	updated_str+="#$";
	int len=updated_str.length();
	int r=0,c=0,palind[len+1]={0};
	for(int i=1;i<len;i++)
	{
		int mirr=2*c-i;
		if(i<r)
			palind[i]=min(r-i,palind[mirr]);
		while(updated_str[i+(1+palind[i])]==updated_str[i-(1+palind[i])])
			palind[i]++;
		if(i+palind[i]>r)
		{
			r=i+palind[i];
			c=i;
		}
	}

	int ans=0;
	c=0;
	for(int i=1;i<len;i++)
	{
		// cout<<palind[i]<<endl;
		if(palind[i]>ans)
		{
			ans=palind[i];
			c=i;
		}
	}
	cout<<ans<<endl;
	if(updated_str[c]=='#')
	{
		for(int i=c-palind[c]+1;i<c+palind[c];i+=2)
			cout<<updated_str[i];
	}
	else
	{
		for(int i=c-palind[c]+1;i<c+palind[c];i+=2)
			cout<<updated_str[i];
	}
	return 0;
}