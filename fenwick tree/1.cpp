#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 2005
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll arr[MAX]={0};
void update(int indx,ll val,int n){
	while(indx<=n){
		arr[indx]=((arr[indx]+val)%MOD+MOD)%MOD;
		indx=indx+(indx&(-indx));
	}
}

ll query(int indx){
	ll ans=0;
	while(indx>0){
		ans=(ans+arr[indx]);
		indx=indx-(indx&(-indx));
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	ll phi[MAX];
	for(int i=0;i<MAX;++i)
		phi[i]=i;
	for(int i=2;i<MAX;++i){
		if(phi[i]==i){
			for(int j=i;j<MAX;j+=i)
				phi[j]=phi[j]-phi[j]/i;
		}		
	}
	ll f[MAX]={0};
	for(int i=1;i<MAX;++i){
		for(int j=i;j<MAX;j+=i){
			f[j]=f[j]+i*phi[j/i];
		}
	}


	int n;
	cin>>n;
	std::vector<int> v(n+1);
	for(int i=1;i<=n;++i){
		cin>>v[i];
		update(i,f[v[i]],n);
	}
	int q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		int x,y;
		cin>>x>>y;
		if(type=='C'){
			ll ans=query(y)-query(x-1);
			ans=(ans%MOD+MOD)%MOD;
			cout<<ans<<endl;
		}
		else{
			ll val=f[y]-f[v[x]];
			v[x]=y;
			update(x,val,n);
		}
	}
	return 0;
}
