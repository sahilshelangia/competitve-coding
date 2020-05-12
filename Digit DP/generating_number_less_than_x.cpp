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
vector<int>digits;
void digit_dp(int indx,int num,int n,int flag){
	if(indx==n){
		cout<<num<<endl;
		return ;
	}
	if(flag==1){
		for(int i=0;i<=digits[indx];i++){
			if(i==digits[indx])
				digit_dp(indx+1,num*10+i,n,1);
			else
				digit_dp(indx+1,num*10+i,n,0);
		}
	}
	else{
		for(int i=0;i<=9;i++)
			digit_dp(indx+1,num*10+i,n,0);
	}

}
int main()
{
	fast;
	int x;
	cin>>x;
	while(x){
		digits.pb(x%10);
		x/=10;
	}
	// 1 means restricted
	reverse(digits.begin(),digits.end());
	digit_dp(0,0,digits.size(),1);
	return 0;
}