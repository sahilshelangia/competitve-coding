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
int bit[26][MAX],n;
void update(int indx,int x,int val){
	while(x<=n){
		bit[indx][x]+=val;
		x+=x&-x;
	}
}
int query(int indx,int x){
	int ans=0;
	while(x>0){
		ans=ans+bit[indx][x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	string s;
	cin>>s;
	n=s.length();

	s="#"+s;
	unordered_set<int>rem[26];
	int cnt[26]={0};
	for(int i=1;i<=n;++i){
		int x=s[i]-'a';
		cnt[x]++;
		update(x,cnt[x],1);
	}
	int q;
	cin>>q;
	while(q--){
		char x;
		int k;
		cin>>k>>x;
		int indx=x-'a';
		int l=1,h=n,pos;
		while(l<=h){
			int mid=(l+h)/2;
			int tmp=query(indx,mid);
			if(tmp>=k){
				pos=mid;
				h=mid-1;
			}
			else
				l=mid+1;
		}
		rem[indx].insert(pos);
		update(indx,pos,-1);
	}	
	// for(int i=0;i<26;++i){
	// 	cout<<i<<": ";
	// 	for(int x:rem[i])
	// 		cout<<x<<" ";
	// 	cout<<endl;
	// }
	memset(cnt,0,sizeof(cnt));
	string ans;
	for(int i=1;i<=n;++i){
		int x=s[i]-'a';
		cnt[x]++;
		if(rem[x].find(cnt[x])==rem[x].end()){
			ans+=s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}