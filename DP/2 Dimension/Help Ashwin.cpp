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
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		}
		int lar=0,lari=0,sec=0,seci=0;
		for(int j=0;j<m;j++)
		{
			if(arr[0][j]>lar)
			{
				sec=lar;
				seci=lari;
				lar=arr[0][j];
				lari=j;
			}
			else if(arr[0][j]>sec)
			{
				sec=arr[0][j];
				seci=j;
			}
		}

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j==lari)
					arr[i][j]+=sec;
				else
					arr[i][j]+=lar;
			}
			sec=lar,lar=0;
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]>lar)
				{
					if(lar>sec)
					{
						sec=lar;
						seci=lari;
					}
					lar=arr[i][j];
					lari=j;
				}
				else if(arr[i][j]>sec)
				{
					sec=arr[i][j];
					seci=j;
				}
			}
		}
		cout<<max(lar,sec)<<endl;
	}
	return 0;
}