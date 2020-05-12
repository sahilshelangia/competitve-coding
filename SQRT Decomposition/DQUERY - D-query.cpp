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
struct query{
	int l,r,indx;
};
int block_size;
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
int freq[1000005]={0},cnt=0,arr[100000];

void add(int indx){
	freq[arr[indx]]++;
	if(freq[arr[indx]]==1)
		cnt++;
}

void remove(int indx){
	freq[arr[indx]]--;
	if(freq[arr[indx]]==0)
		cnt--;
}
int main()
{
	#ifndef LOCAL
	fast;
	#endif
	int n;
	cin>>n;
	block_size=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int q;
	cin>>q;
	query qr[q];
	for(int i=0;i<q;i++){
		cin>>qr[i].l>>qr[i].r;
		qr[i].indx=i+1;
	}
	sort(qr,qr+q,cmp);
	int ans[q+1];
	int curr_l=1,curr_r=0;
	for(int i=0;i<q;i++){
		int l=qr[i].l,r=qr[i].r;
		while(curr_l<l){
			remove(curr_l);
			curr_l++;
		}
		while(curr_l>l){
			curr_l--;
			add(curr_l);
		}
		while(curr_r<r){
			curr_r++;
			add(curr_r);
		}
		while(curr_r>r){
			remove(curr_r);
			curr_r--;
		}
		ans[qr[i].indx]=cnt;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}