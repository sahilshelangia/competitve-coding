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
int bit[10][MAX]={0},n;
void update(int indx,int x,int val){
	while(x<=n){
		bit[indx][x]+=val;
		x+=x&-x;
	}
}
int query(int indx,int x){
	int ans=0;
	while(x>0){
		ans+=bit[indx][x];
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
	int arr[n+1];
	for(int i=1;i<=n;++i){
		arr[i]=s[i-1]-'0';
		update(arr[i],i,1);
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int x,y;
			cin>>x>>y;
			update(arr[x],x,-1);
			arr[x]=y;
			update(arr[x],x,1);
		}
		else{
			int l,r,x;
			cin>>l>>r>>x;
			int freq[10]={0},sum=0;
			for(int i=0;i<10;++i){
				freq[i]=query(i,r)-query(i,l-1);
				sum=sum+freq[i]*i;
				sum=sum%9;
			}
			int extra=9-sum%9;
			freq[extra]++;
			int i=9;
			while(1){
				if(x<=freq[i]){
					cout<<i<<endl;
					break;
				}
				x=x-freq[i];
				--i;
			}
		}
	}
	return 0;
}