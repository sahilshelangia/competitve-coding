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
	int val;
	node *left,*right;
};

node * newNode(int val){
	node *tmp=new node;
	tmp->val=val;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

node * insert(node * root,int val)
{
	if(root==NULL)
		return newNode(val);
	else{
		if(val<=root->val)
			root->left=insert(root->left,val);
		else
			root->right=insert(root->right,val);	

		return root;
	}
}

void preOrder(node * ptr){
	if(ptr){
		cout<<ptr->val<<endl;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

node * find(node * root,int q){
	if(root->val==q)
		return root;
	if(q<=root->val)
		return find(root->left,q);
	else
		return find(root->right,q);
}
int main()
{
	fast;
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++){
		ll val;
		cin>>val;
		root=insert(root,val);
	}
	ll q;
	cin>>q;
	node * ptr=find(root,q);
	preOrder(ptr);
	return 0;
}