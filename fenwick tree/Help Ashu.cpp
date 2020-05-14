#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define int long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define MAX 300000
#define infi 1e12
#define intial 0
#define waiting 1
#define visited 2
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int even[MAX]={0},arr[MAX],n;
void update(int indx,int val,int n){
	while(indx<=n){
		even[indx]+=val;
		indx+=indx&-indx;
	}
}

int query(int indx){
	int ans=0;
	while(indx>0){
		ans+=even[indx];
		indx-=indx&-indx;
	}
	return ans;
}
int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		update(i,arr[i]%2==0,n);
	}
	int q;
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==0){
			if(arr[x]%2==0)
				update(x,-1,n);
			arr[x]=y;
			if(arr[x]%2==0)
				update(x,1,n);
		}
		else if(t==1){
			cout<<query(y)-query(x-1)<<endl;
		}
		else{
			int ans=y-x+1-(query(y)-query(x-1));
			cout<<ans<<endl;
		}
	}
	return 0;
}