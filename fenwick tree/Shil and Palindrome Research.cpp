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
int BIT[26][MAX],n;
void update(int indx,int x,int val){
	while(x<=n){
		BIT[indx][x]+=val;
		x+=x&-x;
	}
}
int query(int indx,int x){
	int ans=0;
	while(x>0){
		ans+=BIT[indx][x];
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
	string s;
	cin>>s;
	s="#"+s;
	for(int i=1;i<=n;++i)
		update(s[i]-'a',i,1);
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int indx;
			char ch;
			cin>>indx>>ch;
			int x=s[indx]-'a';
			update(x,indx,-1);
			s[indx]=ch;
			x=s[indx]-'a';
			update(x,indx,+1);
		}
		else{
			int l,r;
			cin>>l>>r;
			int odd=0;
			for(int i=0;i<26;++i){
				int x=query(i,r)-query(i,l-1);
				// cout<<i<<": "<<x<<endl;
				if(x%2)
					odd++;
			}
			if(odd<=1)
				cout<<"yes\n";
			else
				cout<<"no\n";
		}
	}
	return 0;
}