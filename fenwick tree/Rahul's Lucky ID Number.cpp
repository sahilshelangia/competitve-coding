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
int luck(int x){
	x=__builtin_popcount(x);
	if(x==2)
		return 1;
	return 0;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int t;
	cin>>t;
	while(t--){
		memset(bit,0,sizeof(bit));
		cin>>n;
		int arr[n+1];
		for(int i=1;i<=n;++i){
			cin>>arr[i];
			arr[i]=luck(arr[i]);
			update(i,arr[i]);
		}
		int q;
		cin>>q;
		while(q--){
			int m,p,q;
			cin>>m>>p>>q;
			if(m==1){
				update(p,-arr[p]);
				arr[p]=luck(q);;
				update(p,arr[p]);
			}
			else{
				int ans=0;
				if(p<=q)
					ans=query(q)-query(p-1);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}