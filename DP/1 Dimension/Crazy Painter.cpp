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
		ll n;
		cin>>n;
		ll cost[27];
		for(int i=1;i<=26;i++)
			cin>>cost[i];
		ll rep=n*12/26,rem=(n*12)%26;
		ll ans=0;
		for(int i=1;i<=26;i++)
			ans=ans+rep*(2*cost[i]+rep-1)/2;
		if(rem)
		{
			for(int i=1;i<=rem;i++)
			{
				ans=ans+cost[i]+rep;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}