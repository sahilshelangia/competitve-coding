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
	map<char,node*>children;
	bool isEndOfWord;
	int cnt;
};

node *getNode(){
	node *root=new node();
	root->isEndOfWord=false;
	root->cnt=0;
	return root;
}

void insert(node *root,string s){
	for(int i=0;i<s.length();i++){
		if((root->children).find(s[i])==(root->children).end())
			root->children[s[i]]=getNode();
		root=root->children[s[i]];
	}
	if(root->isEndOfWord==false){
		root->isEndOfWord=true;
		root->cnt=-1;
		cout<<s<<endl;
	}
	else{
		root->cnt++;
		cout<<s<<root->cnt<<endl;
	}
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
	return 0;
}