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
ll sum[MAX]={0},cnt[MAX]={0},n;
void update(int x,ll val,ll *bit){
	while(x<=n){
		bit[x]+=val;
		x+=x&-x;
	}
}
ll query(int x,ll *bit){
	ll ans=0;
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
	ll arr[n+1];
	for(ll i=1;i<=n;++i){
		cin>>arr[i];
		update(i,arr[i],cnt);
		update(i,i*arr[i],sum);
	}
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			ll k,l,r;
			cin>>k>>l>>r;
			// less than k and greater than equal to l
			ll ans=0;
			if(k<l){
				ll c=query(r,cnt)-query(l-1,cnt),s=query(r,sum)-query(l-1,sum);
				ans=s-c*k;
			}
			else if(k>=l&&k<=r){
				ll c=query(k,cnt)-query(l-1,cnt),s=query(k,sum)-query(l-1,sum);
				ans=c*k-s;

				c=query(r,cnt)-query(k,cnt),s=query(r,sum)-query(k,sum);
				ans+=s-c*k;
			}
			else{
				ll c=query(r,cnt)-query(l-1,cnt),s=query(r,sum)-query(l-1,sum);
				ans=c*k-s;
			}
			cout<<ans<<endl;
		}
		else{
			ll k,s;
			cin>>k>>s;
			arr[k]+=s;
			update(k,s,cnt);
			update(k,k*s,sum);
		}
	}	
	return 0;
}