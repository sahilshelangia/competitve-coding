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
	int n;
	cin>>n;
	int deno[n];
	for(int i=0;i<n;i++)
		cin>>deno[i];
	sort(deno,deno+n);
	ll maxDeno=2*deno[n-1];
	bool prev[maxDeno],current[maxDeno];
	memset(prev,false,maxDeno);
	prev[0]=current[0]=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<maxDeno;j++)
		{
			if(deno[i]>j)
				current[j]=prev[j];
			else
				current[j]=prev[j]||current[j-deno[i]];
		}
		for(int j=0;j<maxDeno;j++)
		{
			prev[j]=current[j];
			current[j]=false;
		}
		current[0]=true;
	}
	ll ans=-1;
	// for(int i=0;i<maxDeno;i++)
	// 	cout<<i<<": "<<prev[i]<<endl;
	for(int i=deno[n-1]+1;i<maxDeno;i++)
	{
		// cout<<i<<endl;
		if(prev[i]==false)
		{
			ans=i;
			break;
		}
	}
	if(ans==-1)
		cout<<"Fake Offer!"<<endl;
	else
		cout<<ans<<endl;

	return 0;
}