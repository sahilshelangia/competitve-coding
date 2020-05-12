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
		ll arr[n+1],nge[n+1];
		for(ll i=1;i<=n;i++)
			cin>>arr[i];
		stack<ll>s;
		s.push(1);
		for(ll i=2;i<=n;i++)
		{
			ll x=s.top();
			if(arr[x]>=arr[i])
				s.push(i);
			else
			{
				while(!s.empty()&&arr[s.top()]<arr[i])
				{
					nge[s.top()]=i;
					s.pop();
				}
				s.push(i);
			}
		}
		while(!s.empty())
		{
			nge[s.top()]=-1;
			s.pop();
		}
		for(ll i=1;i<=n;i++)
		{
			if(nge[i]==-1)
				cout<<-1<<" ";
			else
				cout<<arr[nge[i]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}