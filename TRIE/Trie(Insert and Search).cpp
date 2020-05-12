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
#define ALPHABET_SIZE 26
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE]; 
	bool isEndOfWord;
};

TrieNode * getNode(void){
	TrieNode *pNode=new TrieNode;
	pNode->isEndOfWord = false;   
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL;  
    return pNode;
}

void insert(TrieNode *root,string key)
{
	TrieNode *pCrawl=root;
	int len=key.length();
	for(int i=0;i<len;i++){
		int index=int(key[i]-'a');
		if(!pCrawl->children[index])
			pCrawl->children[index]=getNode();
		pCrawl=pCrawl->children[index];
	}
	pCrawl->isEndOfWord=true;
}

bool search(TrieNode *root,string key)
{
	TrieNode *pCrawl=root;
	int len=key.length();
	for(int i=0;i<len;i++){
		int index=int(key[i]-'a');
		if(!pCrawl->children[index])
			return false;
		pCrawl=pCrawl->children[index];
	}
	return (pCrawl!=NULL&&pCrawl->isEndOfWord);
}

int main()
{
	fast;
	int t;
	cin>>t;
	while(t--){
		struct TrieNode *root=getNode();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			insert(root,s);
		}
		string s;
		cin>>s;
		if(search(root,s))
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}