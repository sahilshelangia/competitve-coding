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
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		ll arr[n+1];
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		queue<int>q;
		int status[n+1],dis[n+1];
		memset(status,intial,sizeof(status));
		memset(dis,-1,sizeof(dis));
		q.push(x);
		dis[x]=0;
		status[x]=waiting;
		while(!q.empty()){
			int u=q.front();
			if(u==y)
				break;
			q.pop();
			status[u]=visited;
			ll left=u-arr[u];
			if(left<=0){
				left=left%n;
				left+=n;
			}
			ll right=u+arr[u];
			if(right>n){
				right=right%n;
			}

			if(status[left]==intial){
				status[left]=waiting;
				dis[left]=dis[u]+1;
				q.push(left);
			}

			if(status[right]==intial){
				status[right]=waiting;
				dis[right]=dis[u]+1;
				q.push(right);
			}				
		}
		cout<<dis[y]<<endl;
	}
	return 0;
}