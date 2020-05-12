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


ll count(ll n)
{
	ll res[3][3]={
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	ll trans[3][3]={
		{1,1,1},
		{1,0,0},
		{0,1,0}
	};
	while(n)
	{
		if(n&1)
		{
			ll tmp[3][3]={0};
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					tmp[i][j]=0;
					for(int k=0;k<3;k++)
					{
						tmp[i][j]=(tmp[i][j]+(res[i][k]*trans[k][j])%MOD)%MOD;
					}
				}
			}
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					res[i][j]=tmp[i][j];
		}
		n=n/2;
		ll tmp[3][3]={0};
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				tmp[i][j]=0;
				for(int k=0;k<3;k++)
				{
					tmp[i][j]=(tmp[i][j]+(trans[i][k]*trans[k][j])%MOD)%MOD;
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				trans[i][j]=tmp[i][j];
				// cout<<trans[i][j]<<" ";
			}
			// cout<<endl;
		}
	}
	ll ans=(res[0][0]*7+res[0][1]*4+res[0][2]*2)%MOD;
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans;
		if(n==1)
			ans=1;
		else if(n==2)
			ans=4;
		else if(n==3)
			ans=7;
		else
			ans=count(n-3)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}