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
struct Data{
	int type,a,x;
	Data(int t){
		type=t;
	}
	Data(int t,int aa){
		type=t;
		a=aa;
	}
	Data(int t,int aa,int xx){
		type=t;
		a=aa;
		x=xx;
	}
	Data(){

	}
};

int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int q;
	cin>>q;
	std::vector<Data>v(q+1);
	int ans[q+1];
	std::vector<int>tmp;
	std::vector<pair<int,int> >tim[q+1];
	for(int i=1;i<=q;++i){
		int type;
		cin>>type;
		if(type==0){
			v[i]=(Data(type));
		}
		else if(type==1){
			int a;
			cin>>a;
			v[i]=(Data(type,a));
			tmp.pb(a);
		}
		else{
			int k,x;
			cin>>k>>x;
			v[i]=(Data(type,k,x));
			tmp.pb(x);
			tim[k].pb(mp(x,i));
		}
	}	
	sort(all(tmp));
	int cnt=1;
	unordered_map<int,int>cc;
	for(int i=0;i<tmp.size();++i){
		if(cc.find(tmp[i])==cc.end())
			cc[tmp[i]]=++cnt;
	}

	stack<int>stk;
	for(int i=1;i<=q;++i){
		// cout<<i<<":"<<v[i].type<<"=";
		if(v[i].type==0){
			int x=stk.top();
			stk.pop();
			// cout<<x<<endl;
			update(x,-1);
			
		}
		else if(v[i].type==1){
			int x=v[i].a;
			x=cc[x];
			stk.push(x);
			// cout<<x<<endl;
			update(x,1);
		}
		

		// cout<<endl<<endl;
		// cout<<"oper:";
		for(int j=0;j<tim[i].size();++j){
			int x=tim[i][j].first;
			// cout<<x<<endl;
			x=cc[x];
			ans[tim[i][j].second]=query(x-1);
			// cout<<"==="<<tim[i][j].second<<"::"<<query(x-1)<<endl;
		}
		// cout<<endl<<endl;
	}
	for(int i=1;i<=q;++i){
		if(v[i].type==2){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}