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
	string p;
	cin>>p;
	int len=p.length();
	int ans=MAX;
	for(int i=0;i<=len;i++){
		int left=i,right=len-1;
		int cost=i;
		while(left<=right){
			if(p[left]!=p[right])
				cost++;
			left++;
			right--;
		}
		ans=min(ans,cost);
	}		
	cout<<ans<<endl;

	return 0;
}