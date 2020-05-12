#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
#define eps 1e-9
#define infi 1000000
#define intial 0
#define waiting 1
#define visited 2
#define nill -1
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int n,rootN;
struct info
{
	int l,r,x,indx;
};

bool cmp(info a,info b){
	if(a.l/rootN<=b.l/rootN){
		if(a.l/rootN==b.l/rootN){
			return a.r<=b.r;
		}
		else
			return true;
	}
	else
		return false;
}

struct node
{
	node *children[2];
	int cnt;
};

node *getNode(){
	node *root=new node();
	root->children[0]=root->children[1]=NULL;
	root->cnt=0;
	return root;
}

void insert(node *root,int x){
	for(int i=30;i>=0;i--){
		int indx=0;
		if(x&(1<<i))
			indx=1;
		if(root->children[indx]==NULL)
			root->children[indx]=getNode();
		root=root->children[indx];
	}
	root->cnt++;
}

node * remove(node *root,int x,int dis){
	// cout<<dis<<endl;
	if(dis==-1){
		root->cnt--;
		if(root->cnt==0){
			delete(root);
			root=NULL;
		}
		return root;
	}
	else{
		if(x&(1<<dis))
			root->children[1]=remove(root->children[1],x,dis-1);
		else
			root->children[0]=remove(root->children[0],x,dis-1);

		if(root->children[0]==NULL&&root->children[1]==NULL){
			delete(root);
			root=NULL;
		}
		return root;
	}
}

int minXor(node *root,int x){
	int ans=0;
	for(int i=30;i>=0;i--){
		int indx=0;
		if(x&(1<<i))
			indx=1;
		if(root->children[indx]){
			if(indx==1)
				ans=ans+(1<<i);
			root=root->children[indx];
		}
		else{
			indx=1^indx;
			if(indx==1)
				ans=ans+(1<<i);
			root=root->children[indx];
		}
	}
	return ans;
}
int main()
{
	fast;
	cin>>n;
	rootN=sqrt(n);
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int q;
	cin>>q;
	info query[q];
	for(int i=0;i<q;i++){
		cin>>query[i].l>>query[i].r>>query[i].x;
		query[i].indx=i;
	}
	sort(query,query+q,cmp);
	
	// for(int i=0;i<q;i++){
	// 	cout<<query[i].l<<" "<<query[i].r<<" "<<query[i].x<<" "<<query[i].indx<<endl;
	// }

	node *root=getNode();
	int L=1,R=0,ans[q][2];
	map<int,int>m;
	for(int i=0;i<q;i++){
		int l=query[i].l,r=query[i].r;
		while(r>R){
			R++;
			m[arr[R]]++;
			insert(root,arr[R]);
		}

		while(r<R){
			remove(root,arr[R],30);
			m[arr[R]]--;
			R--;
		}

		while(l>L){
			remove(root,arr[L],30);
			m[arr[L]]--;
			L++;
		}

		while(l<L){
			L--;
			m[arr[L]]++;
			insert(root,arr[L]);
		}

		ans[query[i].indx][0]=minXor(root,query[i].x);
		ans[query[i].indx][1]=m[ans[query[i].indx][0]];
	}
	for(int i=0;i<q;i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	return 0;
}