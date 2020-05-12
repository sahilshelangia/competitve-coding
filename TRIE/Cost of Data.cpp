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

struct node{
	node *children[26];
	bool isEndOfWord;
};

node *getNode(){
	node *tmp=new node();
	for(int i=0;i<26;i++)
		tmp->children[i]=NULL;
	tmp->isEndOfWord=false;
	return tmp;
}

void insert(node *root,string s){
	int len=s.length();
	node *pCrawl=root;
	for(int i=0;i<len;i++){
		int indx=s[i]-'a';
		if(pCrawl->children[indx]==NULL){
			pCrawl->children[indx]=getNode();
		}
		pCrawl=pCrawl->children[indx];
	}
	pCrawl->isEndOfWord=true;
}

int countNode(node *root){
	if(root==NULL)
		return 0;
	int ans=1;
	for(int i=0;i<26;i++){
		if(root->children[i]){
			ans=ans+countNode(root->children[i]);
		}
	}
	return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
	node *root=getNode();
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		insert(root,s);
	}
	int ans=countNode(root);
	cout<<ans<<endl;
	return 0;
}