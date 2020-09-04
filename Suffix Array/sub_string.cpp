#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define MAX 200005
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
const ll MOD=1e9+7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::vector<int>suffix_array(string s){
	int n=s.length();
	std::vector<int> p(n),c(n);
	//for k==0
	{
		std::vector<pair<char,int> >v(n);
		for(int i=0;i<n;++i)
			v[i]=mp(s[i],i);
		sort(all(v));
		for(int i=0;i<n;++i)
			p[i]=v[i].second;
		c[p[0]]=0;
		for(int i=1;i<n;++i){
			if(v[i].first==v[i-1].first)
				c[p[i]]=c[p[i-1]];
			else
				c[p[i]]=c[p[i-1]]+1;
		}
	}
	int k=0;
	while((1<<k)<n){
		std::vector<pair<pair<int,int>,int > > v(n);
		for(int i=0;i<n;++i)
			v[i]=mp(mp(c[i],c[(i+(1<<k))%n]),i);
		
		sort(all(v));
		for(int i=0;i<n;++i)
			p[i]=v[i].second;
		c[p[0]]=0;
		for(int i=1;i<n;++i){
			if(v[i].first==v[i-1].first)
				c[p[i]]=c[p[i-1]];
			else
				c[p[i]]=c[p[i-1]]+1;
		}
		++k;
	}
	return p;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	string t;
	cin>>t;
	t+="$";
	std::vector<int>p=suffix_array(t);
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		int l=0,h=t.length()-1;
		string ans="No\n";
		while(l<=h){
			int m=(l+h)/2;
			int is_greater=0;
			int st=p[m];
			for(int i=0;i<s.length();++i){
				if(s[i]>t[st+i]){
					is_greater=1;
					break;
				}
				else if(s[i]<t[st+i]){
					is_greater=-1;
					break;
				}
			}

			if(is_greater==0){
				ans="Yes\n";
				break;
			}
			if(is_greater==1)
				l=m+1;
			else
				h=m-1;
		}
		cout<<ans;
	}	
	return 0;
}