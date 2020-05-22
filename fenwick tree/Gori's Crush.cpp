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
struct Data
{
	int type,x,y,c,d;
	Data(int tt,int xx,int yy){
		type=tt;
		x=xx;
		y=yy;
	}
	Data(int tt,int l1,int r1,int l2,int r2){
		type=tt;
		x=l1;
		y=r1;
		c=l2;
		d=r2;
	}
	Data(){

	}
};

void common(int &l1,int &r1,int &l2,int &r2){
	if(l2>r2||l1>r1){
		l1=r1+1;
		return ;
	}
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}

	int x=max(l2,l1),y=min(r1,r2);
	l1=x;
	r1=y;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,q,k;
	std::vector<int>tmp;
	cin>>n>>q>>k;
	int arr[n+1];
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		tmp.pb(arr[i]);
	}

	Data qr[q];
	for(int i=0;i<q;++i){
		int type;
		cin>>type;
		if(type==0){
			int x,y;
			cin>>x>>y;
			qr[i]=Data(type,x,y);
			tmp.pb(y);
		}
		else{
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			qr[i]=Data(type,l1,r1,l2,r2);
			tmp.pb(l1);
			tmp.pb(l2);
			tmp.pb(r1);
			tmp.pb(r2);
		}
	}
	unordered_map<int,int>hash;
	int cnt=2;
	sort(all(tmp));
	for(int i=0;i<tmp.size();++i){
		if(hash.count(tmp[i])==0)
			hash[tmp[i]]=cnt++;
	}
	for(int i=1;i<=n;++i){
		arr[i]=hash[arr[i]];
		update(arr[i],1);
	}
	for(int i=0;i<q;++i){
		if(qr[i].type==0){
			int x=qr[i].x,y=qr[i].y;
			y=hash[y];
			update(arr[x],-1);
			arr[x]=y;
			update(arr[x],1);
		}
		else{
			int l1=qr[i].x,r1=qr[i].y,l2=qr[i].c,r2=qr[i].d;
			l1=hash[l1];
			r1=hash[r1];
			l2=hash[l2];
			r2=hash[r2];
			common(l1,r1,l2,r2);
			int ans=0;
			if(l1<=r1)
				ans=query(r1)-query(l1-1);
			if(ans>=k)
				cout<<"Propose\n";
			else
				cout<<"Do not propose\n";
		}
	}
	return 0;
}