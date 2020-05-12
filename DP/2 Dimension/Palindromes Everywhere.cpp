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
	reverse(b.begin(),b.end());
	int la=a.length(),lb=b.length();
	int dp[la+1][lb+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=0;
		}
	}
	
	string updated_a;
	int longest_palina[la+2]={0};
	for(int i=0;i<la;i++)
	{
		updated_a+="#";
		updated_a+=a.substr(i,1);
	}
	updated_a+="#";
	// cout<<updated_a<<endl;
	int ula=updated_a.length();
	for(int i=0;i<ula;i++)
	{
		int cnt=0;
		while(i-cnt>=0&&i+cnt<ula&&updated_a[i-cnt]==updated_a[i+cnt])
		{
			if(updated_a[i]!='#')
				longest_palina[i/2-cnt/2]=max(longest_palina[i/2-cnt/2],cnt);
			else
			{
				if(cnt%2==0)
					longest_palina[(i-1)/2-cnt/2+1]=max(longest_palina[(i-1)/2-cnt/2+1],cnt);
			}
			cnt++;
		}
	}
	// for(int i=0;i<la;i++)
	// 	cout<<longest_palina[i]<<" ";

	string updated_b;
	int longest_palinb[lb+2]={0};
	for(int i=0;i<lb;i++)
	{
		updated_b+="#";
		updated_b+=b.substr(i,1);
	}
	updated_b+="#";
	// cout<<updated_b<<endl;
	int ulb=updated_b.length();
	for(int i=0;i<ulb;i++)
	{
		int cnt=0;
		while(i-cnt>=0&&i+cnt<ulb&&updated_b[i-cnt]==updated_b[i+cnt])
		{
			if(updated_b[i]!='#')
				longest_palinb[i/2-cnt/2]=max(longest_palinb[i/2-cnt/2],cnt);
			else
			{
				if(cnt%2==0)
					longest_palinb[(i-1)/2-cnt/2+1]=max(longest_palinb[(i-1)/2-cnt/2+1],cnt);
			}
			cnt++;
		}
	}


	int ans=0;
	for(int i=0;i<=la;i++)
	{
		for(int j=0;j<=lb;j++)
		{
			ans=max(2*dp[i][j]+max(longest_palina[i],longest_palinb[j]),ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}