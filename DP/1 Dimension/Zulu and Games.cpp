#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 505
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

struct segment{
	ll low,high;
};

bool cmp(segment a,segment b)
{
	if(a.low<b.low)
		return true;
	else if(a.low==b.low)
	{
		if(a.high<b.high)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main()
{
	int n;
	cin>>n;
	segment level[n];
	for(int i=0;i<n;i++)
		cin>>level[i].low;
	for(int i=0;i<n;i++)
		cin>>level[i].high;

	sort(level,level+n,cmp);

	bool goodStart[n],goodEnd[n];
	ll dp[n]={0};
	memset(goodStart,false,sizeof(goodStart));
	memset(goodEnd,false,sizeof(goodEnd));

	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=0;j<i;j++)
		{
			if(level[i].low>level[j].high)
			{
				flag=false;
				break;
			}
		}
		goodStart[i]=flag;
	}

	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=i+1;j<n;j++)
		{
			if(level[i].high<level[j].low)
			{
				flag=false;
				break;
			}
		}
		goodEnd[i]=flag;
	}

	// cout<<"Good start: ";
	// for(int i=0;i<n;i++)
	// {
	// 	if(goodStart[i])
	// 		cout<<i<<" ";
	// }
	// cout<<endl;

	// cout<<"Good end: ";
	// for(int i=0;i<n;i++)
	// {
	// 	if(goodEnd[i])
	// 		cout<<i<<" ";
	// }
	// cout<<endl;

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<level[i].low<<" "<<level[i].high<<endl;
	// }
	

	bool check[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			check[i][j]=false;
	}
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		ll rr=10*MOD;
		for(int j=i+1;j<n;j++)
		{
			if(flag)
				break;
			if((level[i].high<level[j].low))
			{
				rr=min(rr,level[j].high);
				if(rr<level[j].low)
					flag=false;
				else
					check[i][j]=true;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(goodStart[i])
			dp[i]=1;
		else
			dp[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(check[j][i])
				dp[i]=(dp[i]+dp[j])%MOD;

	// for(int i=0;i<n;i++)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;

	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(goodEnd[i])
		{
			// cout<<i<<" "<<dp[i]<<endl;	
			ans=(ans+dp[i]*level[i].high)%MOD;
		}
	}
	cout<<ans<<endl;

	return 0;
}