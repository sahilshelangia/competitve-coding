#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 200005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int round(ll x){
	if(x<0)
		return 0;
	int a=x%10;
	while(x>9)
		x/=10;
	if(x==a)
		return 1;
	return 0;
}
int bit[MAX],n;
void update(int x,int val){
	while(x<=n){
		bit[x]+=val;
		x+=x&-x;
	}
}
int query(int x){
	int ans=0;
	while(x>0){
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int q;
	cin>>n>>q;
	int arr[n+1]={0};
	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		arr[i]=round(x);
		update(i,arr[i]);
	}
	while(q--){
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==1){
			cout<<query(r)-query(l-1)<<endl;
		}
		else{
			int val=round(r)-arr[l];
			arr[l]=round(r);
			update(l,val);
		}
	}
	return 0;
}