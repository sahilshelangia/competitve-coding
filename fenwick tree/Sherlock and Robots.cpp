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
ll bit[MAX],n,bit2[MAX];
void update1(int x,int val){
	while(x<=n){
		bit[x]+=val;
		x+=x&-x;
	}
}
ll query1(int x){
	ll ans=0;
	while(x>0){
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}

void update2(int x,int val){
	while(x<=n){
		bit2[x]+=val;
		x+=x&-x;
	}
}
ll query2(int x){
	ll ans=0;
	while(x>0){
		ans+=bit2[x];
		x-=x&-x;
	}
	return ans;
}

int main()
{
	#ifndef LOCAL
	fast;
	#endif
	n=MAX-1;

	int t;
	cin>>t;
	std::vector<pair<int,int> >v(t);
	for(int i=0;i<t;++i)
		cin>>v[i].first>>v[i].second;

	vector<ll>ans(t);
	for(int i=t-1;i>=0;--i){
		int h=v[i].first,intel=v[i].second;
		ll cntr=query2(n)-query2(h-1),cntl=query2(h-1);
		ll tmp=cntr*intel-(query1(n)-query1(h-1))+query1(h-1)-cntl*intel;
		ans[i]=tmp;
		update1(h,intel);
		update2(h,1);
	}
	for(ll x:ans)
		cout<<x<<endl;
	return 0;
}