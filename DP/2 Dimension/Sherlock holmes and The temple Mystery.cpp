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
		int n;
		cin>>n;
		int arr[n+1],sum=0;
		for(int i=1;i<=n;i++)
			cin>>arr[i],sum+=arr[i];
		bool dp[n+1][sum+1];
		memset(dp,false,sizeof(dp));
		dp[0][0]=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=sum;j++){
				if(j==0)
					dp[i][j]=true;
				else{
					if(arr[i]>j)
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i]];
				}
			}
		}
		if(sum%2==1)
			cout<<"NO"<<endl;
		else{
			if(dp[n][sum/2])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}