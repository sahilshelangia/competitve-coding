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
int bit[MAX];
void update(int x,int val){
	while(x<MAX){
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
	map<string,int>price,cnt;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		int p;
		cin>>s>>p;
		price[s]=p;
		cnt[s]=0;
	}
	int q;
	cin>>q;
	while(q--){
		char type;
		cin>>type;
		if(type=='+'){
			string s;
			cin>>s;
			cnt[s]++;
			update(price[s],1);
		}
		else if(type=='-'){
			string s;
			cin>>s;
			if(cnt[s]>0){
				cnt[s]--;
				update(price[s],-1);
			}
		}
		else{
			int y;
			cin>>y;
			int ans=query(MAX-1)-query(y);
			cout<<ans<<endl;
		}
	}
	return 0;
}