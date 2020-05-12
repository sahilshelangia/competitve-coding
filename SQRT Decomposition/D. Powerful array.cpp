#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define endl '\n'
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

int block_size;
struct query
{
	int l,r,indx;
};
bool cmp(query a,query b){
	if(a.l/block_size<b.l/block_size)
		return true;
	else if(a.l/block_size==b.l/block_size){
		if(a.r<b.r)
			return true;
		return false;
	}
	else
		return false;
}
ll arr[MAX],freq[1000005]={0};
ll curr_ans=0;
void add(int x){
	curr_ans-=freq[x]*freq[x]*x;
	freq[x]++;
	curr_ans+=freq[x]*freq[x]*x;
}
void remove(int x){
	curr_ans-=freq[x]*freq[x]*x;
	freq[x]--;
	curr_ans+=freq[x]*freq[x]*x;	
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,t;
	cin>>n>>t;
	block_size=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	query q[t];
	for(int i=0;i<t;i++){
		cin>>q[i].l>>q[i].r;
		q[i].indx=i;
	}
	sort(q,q+t,cmp);
	int curr_l=1,curr_r=0;
	ll ans[t];
	for(int i=0;i<t;i++){
		int l=q[i].l,r=q[i].r;
		while(curr_l<l){
			remove(arr[curr_l]);
			curr_l++;
		}
		while(curr_l>l){
			curr_l--;
			add(arr[curr_l]);
		}
		while(curr_r<r){
			curr_r++;
			add(arr[curr_r]);
		}
		while(curr_r>r){
			remove(arr[curr_r]);
			curr_r--;
		}
		ans[q[i].indx]=curr_ans;
	}
	for(int i=0;i<t;i++)
		cout<<ans[i]<<endl;
	return 0;
}