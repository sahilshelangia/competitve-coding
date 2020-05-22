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
int bitl[MAX],bitr[MAX];
void update(int x,int val,int *bit){
	while(x<MAX){
		bit[x]+=val;
		x+=x&-x;
	}
}
int query(int x,int *bit){
	int ans=0;
	while(x>0){
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}
void cc(std::vector<int>&v){
	std::vector<int>tmp;
	for(int x:v)
		tmp.pb(x);
	sort(all(tmp));
	int cnt=2;
	unordered_map<int,int>hash;
	int n=v.size();
	for(int i=0;i<n;++i){
		if(hash.count(tmp[i])==0)
			hash[tmp[i]]=cnt++;
	}
	for(int i=0;i<n;++i)
		v[i]=hash[v[i]];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	std::vector<int>v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	cc(v);
	ll ans=0;
	update(v[0],1,bitl);
	for(int i=1;i<n;++i)
		update(v[i],1,bitr);

	for(int i=1;i<n;++i){
		update(v[i],-1,bitr);
		ll a=query(v[i]-1,bitl),b=query(v[i]-1,bitr);
		ans=ans+a*b;
		ans=ans%MOD;
		update(v[i],1,bitl);
	}
	cout<<ans<<endl;
	return 0;
}