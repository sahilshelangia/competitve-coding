#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 1000005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
ll bit[MAX],n;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void compression(std::vector<int>&v){
	std::vector<int>v1;
	for(int i=0;i<n;++i)
		v1.pb(v[i]);
	sort(all(v1));
	unordered_map<int,int>coorcomp;
	int cnt=0;
	for(int i=0;i<n;++i){
		if(coorcomp.count(v1[i])==0){
			coorcomp[v1[i]]=++cnt;
		}
	}
	for(int i=0;i<n;++i)
		v[i]=coorcomp[v[i]];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	ll k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	compression(v);
	
	vector<ll>f(n);
	for(int i=n-1;i>=0;--i){
		f[i]=query(n)-query(v[i]);
		update(v[i],1);
	}
	sort(all(f));
	ll ans=0;
	int j=0;
	for(int i=1;i<n;++i){
		if(f[i]+f[j]<k)
			j=i-1;
		while(j>=0&&f[i]+f[j]>=k){
			--j;
		}
		ans=ans+i-j-1;
		j=max(j,0);
	}
	cout<<ans<<endl;

	// for(int i=0;i<=n;++i)
	// 	bit[i]=0;
	// ll ans=0;
	// for(int i=0;i<n;++i){
	// 	ll req=max(0LL,k-f[i]-1);
	// 	ll x=query(n)-query(req);
	// 	ans=ans+x;
	// 	if(f[i]>0)
	// 		update(f[i],1);
	// }
	// cout<<ans<<endl;
	return 0;
}