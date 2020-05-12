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
		ll arr[n];
		ll max_ending_here=0,max_so_far=0,x=-MOD;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			x=max(x,arr[i]);
		}
		for(int i=0;i<n;i++)
		{
			max_ending_here+=arr[i];
			if(max_ending_here<0)
				max_ending_here=0;
			if(max_so_far<max_ending_here)
				max_so_far=max_ending_here;
		}
		if(max_so_far==0)
			max_so_far=x;
		cout<<max_so_far<<endl;
	}
	return 0;
}