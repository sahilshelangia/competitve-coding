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
		ll arr[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			arr[i]=arr[i]%n;
		}
		map<ll,vector<ll> >m;
		m[0].pb(0);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=(sum+arr[i])%n;
			// cout<<sum<<endl;
			m[sum].pb(i);
		}
		
		int len=MAX,left=MAX,right=MAX;
		map<ll,vector<ll> >::iterator it;
		for(it=m.begin();it!=m.end();it++)
		{
			// cout<<it->first<<": ";
			for(int j=1;j<it->second.size();j++)
			{
				// cout<<it->second[j]<<" ";
				if(it->second[j]-it->second[j-1]<len)
				{
					left=it->second[j-1]+1;
					right=it->second[j];
					len=right-left+1;
				}
				else if(it->second[j]-it->second[j-1]==len)
				{
					if(it->second[j-1]+1<left)
					{
						left=it->second[j-1]+1;
						right=it->second[j];
					}
				}
			}
			// cout<<endl;
		}

		cout<<left<<" "<<right<<endl;

	}
	return 0;
}