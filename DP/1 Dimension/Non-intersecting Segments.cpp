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
	std::vector<PII> x(n),y(n);
	for(int i=0;i<n;i++)
		cin>>x[i].first>>y[i].first>>x[i].second>>y[i].second;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	std::vector<ll>final;
	if(x[0].first==x[n-1].first&x[0].second==x[n-1].second)
	{
		for(int i=0;i<n;i++)
			final.pb(y[i].second);
	}
	else
	{
		for(int i=0;i<n;i++)
			final.pb(x[i].second);
	}
	
	vector<ll>lis;
	lis.pb(final[0]);
	for(int i=1;i<n;i++)
	{
		int indx=upper_bound(lis.begin(),lis.end(),final[i])-lis.begin();
		if(lis[indx-1]!=final[i])
		{
			if(indx==lis.size())
				lis.pb(final[i]);
			else
				lis[indx]=final[i];
		}
	}
	cout<<lis.size()<<endl;
	return 0;
}