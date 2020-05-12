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
		ll arr[n+1],sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		string ans="NO";
		if(sum%2==0)
		{
			sum=sum/2;
			ll prev[sum+1]={0},current[sum+1]={0};
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=sum;j++)
				{
					if(j==0)
						current[j]=1;
					else
						current[j]=(arr[i]<=j)?(prev[j]||prev[j-arr[i]]):(prev[j]);
				}
				for(int j=0;j<=sum;j++)
					prev[j]=current[j];
			}
			if(current[sum])
				ans="YES";
		}
		cout<<ans<<endl;
	}
	return 0;
}