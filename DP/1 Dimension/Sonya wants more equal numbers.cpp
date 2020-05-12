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
	ll arr[n+1],prefix[n+1]={0};
	for(int i=1;i<=n;i++)
		cin>>arr[i],prefix[i]=prefix[i-1]+arr[i];

	ll ans=0;
	vector<int>values;
	for(int i=1;i<=prefix[n];i++)
	{
		set<int>s;
		s.insert(0);
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			int indx=lower_bound(prefix,prefix+n+1,prefix[j-1]+i)-prefix;
			if(prefix[indx]==prefix[j-1]+i)
			{
				j=indx;
				cnt++;
			}
		}

		if(cnt>ans)
		{
			ans=cnt;
			values.clear();
			values.pb(i);
		}
		else if(ans==cnt)
		{
			values.pb(i);
		}
	}
	cout<<ans<<endl;
	sort(values.begin(),values.end());
	for(int i=0;i<values.size();i++)
		cout<<values[i]<<" ";

	return 0;
}