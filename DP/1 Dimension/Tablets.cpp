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
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	ll left[n+1],right[n+1];
	left[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(arr[i]>arr[i-1])
			left[i]=left[i-1]+1;
		else
			left[i]=1;
	}
	right[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(arr[i]>arr[i+1])
			right[i]=right[i+1]+1;
		else
			right[i]=1;
	}

	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=max(left[i],right[i]);
	cout<<ans<<endl;
	return 0;
}