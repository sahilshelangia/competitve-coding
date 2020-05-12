#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 2050
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

ll dp[MAX][105],cap[MAX][105],n;

ll count(int person,int c){
	// cout<<person<<" "<<c<<endl;
	if(__builtin_popcount(person)==n)
		return 1;
	if(c>100)
		return 0;
	if(dp[person][c]==-1){
		ll ans=0; 
		for(int i=1;i<=n;i++){
			if(cap[i][c]==1&&(person&(1<<i))==0){
				ans=(ans+count(person|(1<<i),c+1))%MOD;
			}
		}
		dp[person][c]=(ans+count(person,c+1))%MOD;	
	}
	return dp[person][c];
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(cap,0,sizeof(cap));
		for(int i=1;i<=n;i++){
			while(1){
				char c;
				int x;
				scanf("%d%c",&x,&c);
				cap[i][x]=1;
				if(c=='\n')
					break;
			}
		}
		// for(int i=1;i<=n;i++)
		// {
		// 	cout<<i<<": "<<endl;
		// 	for(int j=1;j<=100;j++)
		// 		cout<<cap[i][j]<<" ";
		// 	cout<<endl;
		// }
		memset(dp,-1,sizeof(dp));
		ll ans=count(0,1);
		cout<<ans<<endl;		
	}
	return 0;
}