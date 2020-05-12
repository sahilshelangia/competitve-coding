#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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
int dp[MAX][MAX];
bool is_win(int a,int b){
	bool state;
	if(a==1){
		return false;
	}
	else if(b==1){
		return true;
	}
	if(dp[a][b]==-1){
		if(__gcd(a,b)!=1)
			dp[a][b]=is_win(b-1,a)&&is_win(b/__gcd(a,b),a);
		else
			dp[a][b]=is_win(b-1,a);
		return !dp[a][b];
	}
	return !dp[a][b];

}
int main()
{
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a==1&&b==1){
			cout<<"Draw"<<endl;
			continue;
		}
		if(is_win(a,b))
			cout<<"Arjit"<<endl;
		else
			cout<<"Chandu Don"<<endl;
	}
	return 0;
}