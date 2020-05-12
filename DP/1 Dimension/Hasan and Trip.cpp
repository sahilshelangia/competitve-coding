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
double distance(double x1,double y1,double x2, double y2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main()
{
	fast;
	int n;
	cin>>n;
	double arr[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cin>>arr[i][j];
	}
	double dist[n],happ[n],ans[n];
	dist[0]=0;
	happ[0]=arr[0][2];
	ans[0]=happ[0];
	for(int i=1;i<n;i++)
	{
		ans[i]=-MOD;
		for(int j=0;j<i;j++)
		{
			double x=dist[j]+distance(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
			double y=arr[i][2]+happ[j];
			if(y-x>ans[i])
			{
				ans[i]=y-x;
				dist[i]=x;
				happ[i]=y;
			}
		}
	}
	cout<<std::fixed<<ans[n-1]<<endl;
	return 0;
}