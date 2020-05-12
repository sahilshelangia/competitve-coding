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
int n,m;
bool check(int x,int y)
{
	if(x<=n&&x>=1&&y<=m&&y>=1)
		return true;
	return false;
}

int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int arr[n+1][m+1],path[n+1][m+1];
		memset(path,0,sizeof(path));

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];
		}
		path[1][1]=1;
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1&&j==1)
					continue;
				else
				{
					if(check(i-1,j)&&arr[i-1][j]<arr[i][j]&&path[i-1][j]!=0)
						path[i][j]=max(path[i][j],1+path[i-1][j]);

					if(check(i,j-1)&&arr[i][j-1]<arr[i][j]&&path[i][j-1]!=0)
						path[i][j]=max(path[i][j],1+path[i][j-1]);
				}
				ans=max(ans,path[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}