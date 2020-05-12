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
	int t;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		ll arr[n+1][3];
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				cin>>arr[i][j];
		}

		for(int i=2;i<=n;i++){
			arr[i][0]=arr[i][0]+min(arr[i-1][1],arr[i-1][2]);
			arr[i][1]=arr[i][1]+min(arr[i-1][0],arr[i-1][2]);
			arr[i][2]=arr[i][2]+min(arr[i-1][1],arr[i-1][0]);
		}
		ll ans=min3(arr[n][0],arr[n][1],arr[n][2]);
		if(ans<=x)
			cout<<"YES\n"<<x-ans<<endl;
		else
			cout<<"NO\n"<<ans-x<<endl;
	}
	return 0;
}