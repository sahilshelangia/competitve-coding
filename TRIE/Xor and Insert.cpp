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
struct node
{
	node *children[2];
};

node *getNode(){
	node *root=new node();
	root->children[0]=root->children[1]=NULL;
	return root;
}

void insert(node *root,int n){
	for(int i=30;i>=0;i--){
		int indx=0;
		if(n&(1<<i))
			indx=1;
		// cout<<i<<" "<<indx<<endl;
		if(root->children[indx]==NULL)
			root->children[indx]=getNode();
		root=root->children[indx];
	}
	return ;
}

int query(node *root,int n){
	int ans=0;
	for(int i=30;i>=0;i--){
		int indx=0;
		if(n&(1<<i))
			indx=1;
		if(root->children[indx]){
			root=root->children[indx];
		}
		else{
			ans=ans+pow(2,i);
			root=root->children[indx^1];
		}		
	}
	return ans;
}
int main()
{
	fast;
	node *root=getNode();
	insert(root,0);
	int cummXor=0;
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==3){
			int ans=query(root,cummXor);
			cout<<ans<<endl;
		}
		else if(type==2){
			int x;
			cin>>x;
			cummXor=cummXor^x;
		}
		else {
			int x;
			cin>>x;
			x=x^cummXor;
			insert(root,x);
		}
	}
	return 0;
}