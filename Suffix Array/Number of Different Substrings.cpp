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
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	string s;
	cin>>s;
	s+="$";
	ll n=s.length();
	std::vector<int>p(n),c(n);
	{
		// k==0
		std::vector<pair<char,int> >v(n);
		for(int i=0;i<n;++i)
			v[i]=mp(s[i],i);
		sort(all(v));
		for(int i=0;i<n;++i)
			p[i]=v[i].second;
		c[p[0]]=0;
		for(int i=1;i<n;++i){
			if(v[i-1].first==v[i].first)
				c[p[i]]=c[p[i-1]];
			else
				c[p[i]]=c[p[i-1]]+1;
		}
	}	
	int k=0;
	while((1<<k)<n){
		std::vector<pair<pair<int,int> , int> > v(n);
		for(int i=0;i<n;++i)
			v[i]=mp(mp(c[i],c[(i+(1<<k))%n]),i);
		sort(all(v));
		for(int i=0;i<n;++i)
			p[i]=v[i].second;
		c[p[0]]=0;
		for(int i=1;i<n;++i){
			if(v[i-1].first==v[i].first)
				c[p[i]]=c[p[i-1]];
			else
				c[p[i]]=c[p[i-1]]+1;
		}
		++k;
	}

	k=0;
	std::vector<ll>lcp(n);
	for(int i=0;i<n-1;++i){
		int pi=c[i];
		int j=p[pi-1];
		while(s[i+k]==s[j+k])
			++k;
		lcp[pi]=k;
		k=max(0,k-1);
	}

	long long int ans=0;
	for(int i=0;i<n;++i){
		ans=ans+(n-i-1)-lcp[i];
	}
	cout<<ans<<endl;
	return 0;
}