#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 10005
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
	int n,k;
	cin>>n>>k;
	int arr[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];

	int cost[MAX];
	bool prime[MAX];
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j<MAX;j+=i)
				prime[j]=false;
		}
	}

	for(int i=1;i<MAX;i++)
	{
		int ans=0,x=i;
		bool flag=false;
		while(x<=10000)
		{
			if(prime[x])
			{
				flag=true;
				cost[i]=ans;
				break;
			}
			ans++;
			x=x+k;
		}
		if(flag==false)
			ans=-1;
		cost[i]=ans;
	}

	bool flag=false;
	int cx,cy,oper=MAX+10;

	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=n-1;j++)
		{
			if(cost[arr[i][j]]!=-1&&cost[arr[i-1][j-1]]!=-1&&cost[arr[i-1][j+1]]!=-1&&cost[arr[i+1][j-1]]!=-1&&cost[arr[i+1][j+1]]!=-1)
			{
				int tmp=cost[arr[i][j]]+cost[arr[i-1][j-1]]+cost[arr[i-1][j+1]]+cost[arr[i+1][j-1]]+cost[arr[i+1][j+1]];
				if(tmp<oper)
				{
					oper=tmp;
					cx=i;
					cy=j;
					flag=true;
				}
			}
		}
	}
	if(flag)
	{
		cout<<"yes"<<endl;
		cout<<oper<<endl;
		cout<<cx<<" "<<cy<<endl;
	}
	else
		cout<<"no"<<endl;
	return 0;
}