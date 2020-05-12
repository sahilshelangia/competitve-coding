#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 2505
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
int n,m;
double dp[MAX][51];

double count(ll sum,ll rem){
	if(sum>n*rem)
		return 0;
	if(sum<0||rem<0)
		return 0;
	if(sum==0&&rem==0)
		return 1;
	if(dp[sum][rem]==-1){

		dp[sum][rem]=0;
		for(int i=1;i<=n;i++)
			dp[sum][rem]+=count(sum-i,rem-1);
	}
	return dp[sum][rem];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<MAX;i++)
			for(int j=0;j<51;j++)
			dp[i][j]=-1;
		cin>>m>>n;
		int k;
		cin>>k;
		double freq[MAX]={0},sum=0;
		for(int i=1;i<MAX;i++)
			freq[i]=count(i,m);
		for(int i=0;i<MAX;i++)
			sum+=freq[i];
		double ans=freq[k]/sum;
		int y=0;
		if(ans==0){
			cout<<"0.000 0"<<'\n';
			continue;
		}
		while(ans<1){
			y++;
			ans=ans*10;
		}
		std::cout << std::fixed<< std::setprecision(3)<<ans<<" "<<y<<'\n';
	}
	return 0;
}