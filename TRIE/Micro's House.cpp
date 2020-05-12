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

int power[30];
void insert(node *root,int n){
	for(int i=28;i>=0;i--){
		int indx=0;
		if(n&(1<<i))
			indx=1;
		if(root->children[indx]==NULL)
			root->children[indx]=getNode();
		root=root->children[indx];
	}
}

int query(node *root,int n){
	int ans=0;
	for(int i=28;i>=0;i--){
		int indx=1;
		if(n&(1<<i))
			indx=0;
		if(root->children[indx]){
			ans=ans+power[i];
			root=root->children[indx];
		}
		else
			root=root->children[indx^1];
	}
	return ans;
}

void remove(node *root){
	if(root==NULL)
		return ;
	remove(root->children[0]);
	remove(root->children[1]);
	delete(root);
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	power[0]=1;
	for(int i=1;i<=30;i++)
		power[i]=power[i-1]*2;
	int arr[n+1][m+1],preCompute[n+1][m+1];
	for(int i=0;i<=n;i++)
		preCompute[i][0]=0;
	for(int i=0;i<=m;i++)
		preCompute[0][i]=0;
	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			preCompute[i][j]=preCompute[i][j-1]^arr[i][j];
		}
	}

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<preCompute[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int ans=0;
	for(int len=1;len<=m;len++){
		for(int i=1;i+len-1<=m;i++){
			int start=i,end=i+len-1;
			node *root=getNode();
			int cummXor=0;
			insert(root,cummXor);
			for(int j=1;j<=n;j++){
				cummXor=cummXor^(preCompute[j][start-1]^preCompute[j][end]);
				ans=max(ans,query(root,cummXor));
				insert(root,cummXor);
			}
			remove(root);
		}
	}
	cout<<ans<<endl;
	return 0;
}