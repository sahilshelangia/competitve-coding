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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll bit[MAX],n;
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

void intialize(){
	for(int i=0;i<MAX;++i)
		bit[i]=0;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		intialize();
		int arr[n+1];
		ll ans=0,curr=0,prev=0;
		for(int i=1;i<=n;++i){
			cin>>arr[i];
			curr+=query(MAX-1)-query(arr[i]);
			update(arr[i],1);
		}
		ans=curr;
		prev=curr;
		for(int i=1;i<=n;++i){
			curr=prev-query(arr[i]-1);
			curr=curr+query(MAX-1)-query(arr[i]);
			prev=curr;
			cout<<curr<<" ";
		}
		cout<<endl;
	}	
	return 0;
}