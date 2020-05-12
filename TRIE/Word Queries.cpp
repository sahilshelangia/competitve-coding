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
	node *children[26];
	int count;
	bool isEndOfWord;
};

node *getNode(){
	node *root=new node();
	for(int i=0;i<26;i++)
		root->children[i]=NULL;
	root->count=0;
	root->isEndOfWord=false;
	return root;
}

void insert(node *root,string s){
	node *pCrawl=root;
	int len=s.length();
	for(int i=0;i<len;i++){
		int indx=s[i]-'a';
		if(pCrawl->children[indx]==NULL)
			pCrawl->children[indx]=getNode();

		pCrawl=pCrawl->children[indx];
		(pCrawl->count)++;
	}
	pCrawl->isEndOfWord=true;
	return ;
}

int query(node *root,string s){
	node *pCrawl=root;
	int len=s.length();
	for(int i=0;i<len;i++){
		int indx=s[i]-'a';
		pCrawl=pCrawl->children[indx];
		if(pCrawl==NULL)
			break;
	}
	if(pCrawl==NULL)
		return 0;
	else
		return pCrawl->count;
}
int main()
{
	// fast;
	int n,q;
	cin>>n>>q;
	node *root=getNode();
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		insert(root,s);
	}
	while(q--){
		string s;
		cin>>s;
		cout<<query(root,s)<<endl;
	}
	return 0;
}