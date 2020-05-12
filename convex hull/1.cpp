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
struct pt{
	double x,y;
	pt(){
		x=y=0;
	}
	pt(double a,double b){
		x=a;
		y=b;
	}
};
bool cmp(pt a,pt b){
	return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}

bool cw(pt a,pt b,pt c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a,pt b,pt c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt>convex_hull(std::vector<pt>&a){
	sort(a.begin(),a.end(),cmp);
	if(a[0].x==a.back().x&&a[0].y==a.back().y){
		std::vector<pt>ans;
		ans.pb(a[0]);
		return ans;
	}
	std::vector<pt>up,down;
	pt p1=a[0],p2=a.back();
	up.pb(p1);
	down.pb(p1);
	int n=a.size();
	for(int i=1;i<n;++i){
		if(i==n-1||cw(p1,a[i],p2)){
			while(up.size()>=2&&!cw(up[up.size()-2],up[up.size()-1],a[i]))
				up.pop_back();
			up.pb(a[i]);
		}
		if(i==n-1||ccw(p1,a[i],p2)){
			while(down.size()>=2&&!ccw(down[down.size()-2],down[down.size()-1],a[i]))
				down.pop_back();
			down.pb(a[i]);
		}
	}
	vector<pt>ans;
	for(int i=0;i<down.size();++i)
		ans.pb(down[i]);
	for(int i=up.size()-2;i>=1;--i)
		ans.pb(up[i]);
	return ans;	
}

int main()
{
	#ifndef LOCAL
	fast;
	#endif
	while(1){
		int n;
		cin>>n;
		if(n==0)
			break;
		std::vector<pt>v;
		for(int i=0;i<n;++i){
			int x,y;
			cin>>x>>y;
			v.emplace_back(x,y);
		}
		std::vector<pt>ans=convex_hull(v);
		cout<<ans.size()<<endl;
		for(auto pt:ans)
			cout<<pt.x<<" "<<pt.y<<endl;
		cout<<endl;
	}
	return 0;
}