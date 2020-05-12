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
	node *tmp=new node();
	tmp->children[0]=tmp->children[1]=NULL;
	return tmp;
}

void insert(node *root,int n){
	for(int i=30;i>=0;i--){
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
	for(int i=30;i>=0;i--){
		int indx=0;
		if(n&(1<<i))
			indx=1;
		if(root->children[indx]){
			if(indx)
				ans=ans+(1<<i);
			root=root->children[indx];
		}
		else{
			indx=indx^1;
			if(indx)
				ans=ans+(1<<i);
			root=root->children[indx];
		}
	}
	return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	int dp[n+1][MAX];
	for(int i=0;i<MAX;i++)
		dp[0][i]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<MAX;j++){
			if(j==0)
				dp[i][j]=1;
			else{
				if(arr[i]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i]])%MOD;
			}
		}
	}

	node *root=getNode();
	for(int i=1;i<MAX;i++){
		if(dp[n][i]){
			insert(root,i);
		}
	}


	int q;
	cin>>q;
	while(q--){
		int a;
		cin>>a;
		int num=query(root,a);
		cout<<num<<" "<<dp[n][num]<<endl;
	}
	return 0;
}