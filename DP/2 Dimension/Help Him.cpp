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
	int n;
	cin>>n;
	ll arr[n+1][n+1],going[n+1][n+1],back[n+2][n+2];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	}
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			going[i][j]=0,back[i][j]=MAX;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1)
				going[i][j]=arr[1][1];
			else
				going[i][j]=max(going[i-1][j],going[i][j-1])+arr[i][j];
		}
	}

	cout<<going[n][n]<<" ";

	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(i==n&&j==n)
				back[i][j]=arr[n][n];
			else
				back[i][j]=min(back[i+1][j],back[i][j+1])+arr[i][j];
		}
	}
	
	cout<<back[1][1]<<endl;
	return 0;
}