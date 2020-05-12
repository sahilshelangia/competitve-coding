//let's do it
 #include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a,val) memset(a,val,sizeof a)
#define endl "\n"
#define maxn 820000
ll tr[8*maxn][2],nn=1,cnt[8*maxn][2],arr[905],sum[905];
void add(ll a) {
    ll t = 1;
    for (ll i = 31; i >= 0; --i) {
        int now = (a >> i) & 1;
        if (!tr[t][now]) {
            tr[t][now] = ++nn;
        }
        cnt[t][now]++;
        t = tr[t][now];
    }
}
ll getMax(ll a) {
    ll t = 1, res = 0;
    for (ll i = 31; i >= 0; --i) {
        ll now = (a >> i) & 1;
        now = !now;
        if (tr[t][now] && cnt[t][now]) {
            t = tr[t][now];
            res += (1 << i) * 1;
        } else {
            t = tr[t][!now];
        }
    }
    return res;
}
inline ll getsum(ll l,ll r)
{
	assert(l<=r);
	return sum[r]-sum[l-1];
}
int main()
{
	boost1;boost2;
	ll i,j,n,x,y,val,ans;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>arr[i];
	sum[1]=arr[1];
	for(i=2;i<=n;i++)
	sum[i]=sum[i-1]+arr[i];
	add(arr[n]);
	ans=0;
	for(i=n-1;i>=1;i--)
	{
		for(j=i;j>=1;j--)
		{
			val=getsum(j,i);
			ans=max(ans,getMax(val));
		}
		for(j=i;j<=n;j++)
		{	
			val=getsum(i,j);
			add(val);
		}
	}
	cout<<ans;
	return 0;
}