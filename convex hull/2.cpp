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
	pt(double a,double b){
		x=a;
		y=b;
	}
	pt(){
		x=0,y=0;
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

std::vector<pt>convex_hull(std::vector<pt>&a){
	sort(all(a),cmp);
	int n=a.size();
	pt p1=a[0],p2=a.back();
	std::vector<pt>up,down;
	up.pb(p1);
	down.pb(p1);
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
	std::vector<pt>ans;
	for(int i=0;i<up.size();++i)
		ans.pb(up[i]);
	for(int i=down.size()-2;i>0;--i)
		ans.pb(down[i]);
	return ans;
}
double dis(pt a,pt b){
	double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return len;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,l;
	cin>>n>>l;
	std::vector<pt>v(n);
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		v[i]=pt(x,y);
	}
	vector<pt>ans=convex_hull(v);
	double total=0;
	for(int i=1;i<ans.size();++i){
		total+=dis(ans[i],ans[i-1]);
	}
	total+=dis(ans[0],ans.back());
	total=total;
	double add=3.14159265358979323846;
	add=add*2*l;
	total=total+add;
	total+=0.5;
	ll final=total;
	cout<<final<<endl;
	return 0;
}