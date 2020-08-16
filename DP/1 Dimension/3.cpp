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
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,q;
	cin>>n>>q;
	int arr[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}	
	while(q--){
		int type;
		cin>>type;
		if(type==0){
			int indx,val;
			cin>>indx>>val;
			arr[indx]=val;
		}
		else{
			int l,r;
			cin>>l>>r;
			string ans="Yes";
			if(r-l==0){
				cout<<ans<<endl;
				continue;
			}
			set<int>s;
			for(int i=l;i<=r;++i){
				s.insert(arr[i]);
			}

			if(s.size()!=r-l+1)
				ans="No";
			cout<<ans<<endl;
		}
	}
	return 0;
}