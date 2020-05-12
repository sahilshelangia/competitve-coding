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
	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1];
	ll cumm[n+1][m+1];
	memset(arr,0,sizeof(arr));
	memset(cumm,0,sizeof(cumm));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
			cumm[i][j]=cumm[i-1][j]+cumm[i][j-1]-cumm[i-1][j-1]+arr[i][j];
		}
	}	
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<cumm[x][y]<<endl;
	}
	return 0;
}