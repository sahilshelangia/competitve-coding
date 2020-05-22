#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
#define MAX 105
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll bit[MAX][MAX][MAX]={0},n;
void update(int x,int y,int z,int val){
	while(x<MAX){
		int y1=y;
		while(y1<MAX){
			int z1=z;
			while(z1<MAX){
				bit[x][y1][z1]+=val;
				z1+=z1&-z1;
			}
			y1+=y1&-y1;
		}
		x+=x&-x;
	}
}
ll query(int x,int y,int z){
	ll ans=0;
	while(x>0){
		int y1=y;
		while(y1>0){
			int z1=z;
			while(z1>0){
				ans+=bit[x][y1][z1];
				z1-=z1&-z1;
			}
			y1-=y1&-y1;
		}
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
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int x,y,z,val;
			cin>>x>>y>>z>>val;
			x++;y++;z++;
			update(x,y,z,val);
		}
		else{
			int x1,y1,z1,x2,y2,z2;
			cin>>x1>>y1>>z1>>x2>>y2>>z2;
			x2++;y2++;z2++;
			ll total=query(n+1,n+1,n+1);
			ll res=query(x2,y2,z2)-query(x1,y2,z2)-query(x2,y1,z2)-query(x2,y2,z1)+
					query(x1,y1,z2)+query(x1,y2,z1)+query(x2,y1,z1)-query(x1,y1,z1);
			ll ans=total-res;
			cout<<ans<<endl;
		}
	}
	return 0;
}