// #include<bits/stdc++.h>
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define debug cout<<"here"<<endl;
// #define ll long long int
// #define mp make_pair
// #define pb push_back
// const ll MOD=1e9+7;
// #define MAX 100005
// #define eps 1e-9
// #define infi 1000000
// #define intial 0
// #define waiting 1
// #define visited 2
// #define nill -1
// #define max3(a,b,c) max(a,max(b,c))
// #define min3(a,b,c) min(a,min(b,c))
// #define PII pair<ll,ll>
// #define input freopen("input.txt","r",stdin);
// #define output freopen("output.txt","w",stdout);
// using namespace std;
// int main()
// {
// 	fast;
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++)
// 		cin>>arr[i];
// 	sort(arr,arr+n);
// 	int ans=MAX,left=0,right=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		left=i;
// 		while(right<n&&arr[right]-3*arr[left]<=0)
// 		{
// 			ans=min(ans,n-(right-left+1));
// 			right++;
// 		}
// 		right--;
// 	}
// 	cout<<ans<<endl;
// 	return 0;
// }

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
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ll x=3*arr[i];
		int indx=upper_bound(arr,arr+n,x)-arr-i;
		ans=max(ans,indx);
	}
	cout<<n-ans<<endl;
	return 0;
}