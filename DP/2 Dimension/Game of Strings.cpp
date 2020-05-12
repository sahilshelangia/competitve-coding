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
	string a,b;
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	string na,nb;
	for(int i=0;i<la;i++)
		if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u')
			na+=a[i];

	for(int i=0;i<lb;i++)
		if(b[i]!='a'&&b[i]!='e'&&b[i]!='i'&&b[i]!='o'&&b[i]!='u')
			nb+=b[i];
	na="#"+na;
	nb="$"+nb;
	la=na.length();
	lb=nb.length();
	int dp[la+1][lb+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<la;i++){
		for(int j=1;j<lb;j++){
			if(na[i]==nb[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	// for(int i=0;i<la;i++){
	// 	for(int j=0;j<lb;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[la-1][lb-1]<<endl;
	return 0;
}