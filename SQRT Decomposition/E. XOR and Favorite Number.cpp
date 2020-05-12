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

ll curr_ans=0,block_size,freq[2000005]={0};
struct query{
	int l,r,indx;
};
bool cmp(query a,query b){
	if(a.l/block_size<b.l/block_size)
		return true;
	if(a.l/block_size==b.l/block_size){
		if(a.r<b.r)
			return true;
		return false;
	}
	else
		return false;
}

void add(int x,int k){
	curr_ans+=freq[x^k];
	freq[x]++;
}
void remove(int x,int k){
	freq[x]--;
	curr_ans-=freq[x^k];
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n,m,k;
	cin>>n>>m>>k;
	block_size=sqrt(n);
	int arr[n+1],prefix[n+1]={0};;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		prefix[i]=prefix[i-1]^arr[i];
	}		
	query qr[m];
	// freq[0]=1;
	for(int i=0;i<m;i++){
		cin>>qr[i].l>>qr[i].r;
		qr[i].indx=i;
	}
	sort(qr,qr+m,cmp);
	int curr_l=1,curr_r=0;
	ll ans[m];
	// freq[0]=1;
	for(int i=0;i<m;i++){
		int l=qr[i].l-1,r=qr[i].r;
		while(curr_l<l){
			remove(prefix[curr_l],k);
			curr_l++;
		}
		while(curr_l>l){
			curr_l--;
			add(prefix[curr_l],k);
		}
		while(curr_r<r){
			curr_r++;
			add(prefix[curr_r],k);
		}
		while(curr_r>r){
			remove(prefix[curr_r],k);
			curr_r--;
		}
		ans[qr[i].indx]=curr_ans;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}