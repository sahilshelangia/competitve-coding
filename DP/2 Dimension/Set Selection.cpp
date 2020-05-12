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
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	bool prev[MAX],curr[MAX];
	memset(prev,false,sizeof(prev));
	prev[0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(arr[i]>j)
				curr[j]=prev[j];
			else
				curr[j]=prev[j]||prev[j-arr[i]];
		}
		for(int j=0;j<MAX;j++)
			prev[j]=curr[j];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int z;
		cin>>z;
		if(curr[z])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}