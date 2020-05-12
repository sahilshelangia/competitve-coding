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
	bool endOfWord;
};

node *getNode(){
	node *root=new node();
	for(int i=0;i<26;i++)
		root->children[i]=NULL;
	root->endOfWord=false;
	return root;
}

void insert(node *root,string s){
	for(int i=0;i<s.length();i++){
		int indx=s[i]-'a';
		if(root->children[indx]==NULL)
			root->children[indx]=getNode();
		root=root->children[indx];
	}
	root->endOfWord=true;
}

void print(node *root,string s){
	if(root->endOfWord){
		cout<<s<<endl;
	}
	for(int i=0;i<26;i++){
		if(root->children[i]){
			char x='a'+i;
			string tmp=s+x;
			print(root->children[i],tmp);
		}
	}

}
void query(node *root,string s){
	node *crawl=root;
	for(int i=0;i<s.length();i++){
		int indx=s[i]-'a';
		root=root->children[indx];
		if(root==NULL)
			break;
	}
	if(root!=NULL){
		print(root,s);
	}
	else{
		cout<<"No suggestions"<<endl;
		insert(crawl,s);
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
		bool flag=false;
		for(int j=0;j<s.length();j++){
			if(!(s[j]>='a'&&s[j]<='z')){
				flag=true;
				break;
			}
		}
		if(flag)
			continue;
		insert(root,s);
	}
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		query(root,s);
	}
	return 0;
}