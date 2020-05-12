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
		int n;
		cin>>n;
		char arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}

		int dpl[n][n],dpu[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]=='O')
					dpu[i][j]=dpl[i][j]=0;
				else
				{
					if(i>0&&j>0)
					{
						dpl[i][j]=1+dpl[i][j-1];
						dpu[i][j]=1+dpu[i-1][j];
					}	
					else if(i>0)
					{
						dpl[i][j]=1;
						dpu[i][j]=1+dpu[i-1][j];
					}
					else if(j>0)
					{
						dpl[i][j]=1+dpl[i][j-1];
						dpu[i][j]=1;
					}
					else
					{
						dpl[i][j]=1;
						dpu[i][j]=1;
					}
				}
			}
		}

		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int x=min(dpl[i][j],dpu[i][j]);
				for(int k=x;k>=1;k--)
				{
					if((i-k+1>=0&&j-k+1>=0)&&dpu[i][j-k+1]>=k&&dpl[i-k+1][j]>=k)
					{
						ans=max(ans,k);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}