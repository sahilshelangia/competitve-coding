// https://vjudge.net/problem/LightOJ-1068

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int k,sz;
// digit indx, remainder,digit sum, flag
int dp[12][10005][120][2];
std::vector<int>digits(30);
ll countWays(int indx,int rem,int sum,int flag){
	if(indx==sz){
		return rem==0&&sum%k==0;
	}

	if(dp[indx][rem][sum][flag]!=-1){
		return dp[indx][rem][sum][flag];
	}
	ll ans=0;
	if(flag==0){
		for(int i=0;i<=digits[indx];i++){
			if(i<digits[indx])
				ans=ans+countWays(indx+1,(rem*10+i)%k,sum+i,1);
			else
				ans=ans+countWays(indx+1,(rem*10+i)%k,sum+i,0);
		}
	}
	else{
		for(int i=0;i<=9;i++)
			ans=ans+countWays(indx+1,(rem*10+i)%k,sum+i,1);
	}
	dp[indx][rem][sum][flag]=ans;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		ll a,b;
		cin>>a>>b>>k;
		ll ansa=1,ansb;
		sz=log10(b)+1;
		for(int i=0;b!=0;i++){
			digits[i]=b%10;
			b=b/10;
		}
		for(int i=0;i<sz/2;i++)
			swap(digits[i],digits[sz-i-1]);

		// for(int i=0;i<sz;i++)
		// 	cout<<digits[i];
		// cout<<endl<<sz<<endl;
		// return 0;
		memset(dp,-1,sizeof(dp));
		ansb=countWays(0,0,0,0);
		// cout<<ansb<<endl;

	
		a--;
		if(a!=0){
			// sz=log10(a)+1;
			// return 0;
			for(int i=0;1;i++){
				if(a==0)
					break;
				digits[i]=a%10;
				a=a/10;
			}
			for(int i=0;i<sz/2;i++)
				swap(digits[i],digits[sz-i-1]);
			memset(dp,-1,sizeof(dp));
			ansa=countWays(0,0,0,0);
		}
		
		ll ans=ansb-ansa;
		cout<<"Case "<<test<<": "<<ans<<endl;	
	}
	return 0;
}