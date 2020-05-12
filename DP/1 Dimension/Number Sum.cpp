#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 5005
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	ll sum=0,a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		ll f[MAX]={0};
		ll ans=1;
		for(int j=i;j<n;j++)
		{
			if(a[j]<MAX)
				f[a[j]]=1;
			while(f[ans])
				ans++;
			// cout<<ans<<endl;
			sum+=ans;
		}
	}
	cout<<sum;
	return 0;
}