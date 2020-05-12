#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1000000009;
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
struct exps{
	ll tr,fl;
};
int main()
{
	fast;
	string s,op;
	cin>>s>>op;
	int len=s.length();
	bool ss[len];
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1')
			ss[i]=true;
		else
			ss[i]=false;
	}

	exps dp[len+1][len+1];
	for(int i=0;i<=len;i++)
		for(int j=0;j<=len;j++)
			dp[i][j].tr=0,dp[i][j].fl=0;

	for(int l=1;l<=len;l++)
	{
		for(int i=0;i+l<=len;i++)
		{
			int start=i,end=i+l-1;
			if(start==end)
			{
				if(ss[start])
					dp[start][end].tr=1;
				else
					dp[start][end].fl=1;
			}
			else
			{
				for(int k=1;k<l;k++)
				{
					int l1=start,r1=start+k-1,l2=r1+1,r2=end;
					if(op[r1]=='o')
					{
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].tr*dp[l2][r2].tr)%MOD;
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].tr*dp[l2][r2].fl)%MOD;
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].fl*dp[l2][r2].tr)%MOD;

						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].fl*dp[l2][r2].fl)%MOD;
					}

					else if(op[r1]=='a')
					{
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].tr*dp[l2][r2].tr)%MOD;

						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].tr*dp[l2][r2].fl)%MOD;
						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].fl*dp[l2][r2].tr)%MOD;
						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].fl*dp[l2][r2].fl)%MOD;
					}
					else if(op[r1]=='x')
					{
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].tr*dp[l2][r2].fl)%MOD;
						dp[start][end].tr=(dp[start][end].tr+dp[l1][r1].fl*dp[l2][r2].tr)%MOD;

						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].tr*dp[l2][r2].tr)%MOD;
						dp[start][end].fl=(dp[start][end].fl+dp[l1][r1].fl*dp[l2][r2].fl)%MOD;
					}
				}
			}
		}
	}
	// for(int i=0;i<len;i++)
	// {
	// 	for(int j=0;j<len;j++)
	// 	{
	// 		cout<<"tr="<<dp[i][j].tr<<" fl="<<dp[i][j].fl<<"   ";
	// 	}
	// 	cout<<endl;
	// }

	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;

		string res;
		cin>>res;
		if(res=="true")
		{
			cout<<dp[l][r].tr<<endl;
		}
		else
		{
			cout<<dp[l][r].fl<<endl;
		}
	}
	return 0;
}



// else if(start+1==end)
// {
// 	if(op[start]=='a')
// 	{
// 		if(ss[start]&ss[end])
// 			dp[start][end].tr=1;
// 		else
// 			dp[start][end].fl=1;
// 	}
// 	else if(op[start]=='o')
// 	{
// 		if(ss[start]|ss[end])
// 			dp[start][end].tr=1;
// 		else
// 			dp[start][end].fl=1;
// 	}
// 	else if(op[start]=='x')
// 	{
// 		if(ss[start]^ss[end])
// 			dp[start][end].tr=1;
// 		else
// 			dp[start][end].fl=1;
// 	}
// }