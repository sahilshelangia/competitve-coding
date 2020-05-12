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
		string updt="$";
		int len=s.length();
		for(int i=0;i<len;i++)
			updt+="#"+s.substr(i,1);
		updt+="#@";
		len=updt.length();
		int palin[MAX]={0},c=0,r=0,ans=0;
		for(int i=1;i<len;i++)
		{
			int mirr=2*c-i;
			if(i<r)
				palin[i]=min(r-i,palin[mirr]);
			while(updt[i+(1+palin[i])]==updt[i-(1+palin[i])])
				palin[i]++;
			if(i+palin[i]>r)
			{
				r=i+palin[i];
				c=i;
			}
			ans=max(ans,palin[i]);
		}
		bool flag=false;
		for(int i=2;i*i<=ans;i++)
		{
			if(ans%i==0)
			{
				flag=true;
				break;
			}
		}
		if(ans==1)
			flag=true;
		if(flag)
			cout<<"NOT PRIME"<<endl;
		else
			cout<<"PRIME"<<endl;
	}
	return 0;
}