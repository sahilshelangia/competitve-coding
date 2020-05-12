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
#define SIZE 26
struct TrieNode{
	TrieNode * children[26];
	bool isEndOfWord;
	ll priority;
};

TrieNode * getNode(void)
{
	TrieNode *pNode=new TrieNode;
	for(int i=0;i<SIZE;i++)
		pNode->children[i]=NULL;
	pNode->isEndOfWord=false;
	pNode->priority=0;
	return pNode;
}

void insert(TrieNode *root,string key,ll prior)
{
	TrieNode *pCrawl=root;
	for(int i=0;i<key.length();i++){
		int index=int(key[i]-'a');
		if(pCrawl->children[index]==NULL){
			pCrawl->children[index]=getNode();
			(pCrawl->children[index])->priority=prior;
		}

		(pCrawl->children[index])->priority=max(prior,(pCrawl->children[index])->priority);
		pCrawl=pCrawl->children[index];
	}
	pCrawl->isEndOfWord=true;
}

ll search(TrieNode *root,string key)
{
	if(!root)
		return -1;
	TrieNode *pCrawl=root;
	ll ans=-1;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!(pCrawl->children[index]))
			return -1;
		ans=max(ans,pCrawl->children[index]->priority);
		pCrawl=pCrawl->children[index];
	}
	if(pCrawl!=NULL)
		return ans;
}

int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	TrieNode *root=getNode();
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		ll wt;
		cin>>wt;
		insert(root,s,wt);
	}
	while(q--){
		string s;
		cin>>s;
		ll ans=search(root,s);
		cout<<ans<<endl;
	}
	return 0;
}