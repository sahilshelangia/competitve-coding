#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1005
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
int n,m;
int arr[MAX][MAX];
bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&arr[x][y]!=-1;
}
int main()
{
	fast;
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char tmp;
			cin>>tmp;
			if(tmp=='*')
				arr[i][j]=-1;
			else
				arr[i][j]=int(tmp-'0');
		}
	}
	int x,y;
	cin>>x>>y;
	int dis[n+1][m+1],sum[n+1][m+1],status[n+1][m+1];
	memset(dis,-1,sizeof(dis));
	memset(sum,-1,sizeof(sum));
	memset(status,intial,sizeof(status));
	queue<PII>q;
	q.push(mp(x,y));
	status[x][y]=waiting;
	dis[x][y]=0;
	sum[x][y]=arr[x][y];
	while(!q.empty()){
		int ux=q.front().first,uy=q.front().second;
		q.pop();
		status[ux][uy]=visited;

		int vx,vy;
		vx=ux+1,vy=uy;
		if(check(vx,vy)){
			if(status[vx][vy]==intial){
				status[vx][vy]=waiting;
				dis[vx][vy]=dis[ux][uy]+1;
				sum[vx][vy]=sum[ux][uy]+arr[vx][vy];
				q.push(mp(vx,vy));
			}
			else if(status[vx][vy]==waiting){
				sum[vx][vy]=max(sum[vx][vy],sum[ux][uy]+arr[vx][vy]);
			}
		}

		vx=ux-1,vy=uy;
		if(check(vx,vy)){
			if(status[vx][vy]==intial){
				status[vx][vy]=waiting;
				dis[vx][vy]=dis[ux][uy]+1;
				sum[vx][vy]=sum[ux][uy]+arr[vx][vy];
				q.push(mp(vx,vy));
			}
			else if(status[vx][vy]==waiting){
				sum[vx][vy]=max(sum[vx][vy],sum[ux][uy]+arr[vx][vy]);
			}
		}


		vx=ux,vy=uy+1;
		if(check(vx,vy)){
			if(status[vx][vy]==intial){
				status[vx][vy]=waiting;
				dis[vx][vy]=dis[ux][uy]+1;
				sum[vx][vy]=sum[ux][uy]+arr[vx][vy];
				q.push(mp(vx,vy));
			}
			else if(status[vx][vy]==waiting){
				sum[vx][vy]=max(sum[vx][vy],sum[ux][uy]+arr[vx][vy]);
			}
		}

		vx=ux,vy=uy-1;
		if(check(vx,vy)){
			if(status[vx][vy]==intial){
				status[vx][vy]=waiting;
				dis[vx][vy]=dis[ux][uy]+1;
				sum[vx][vy]=sum[ux][uy]+arr[vx][vy];
				q.push(mp(vx,vy));
			}
			else if(status[vx][vy]==waiting){
				sum[vx][vy]=max(sum[vx][vy],sum[ux][uy]+arr[vx][vy]);
			}
		}
		
	}

	int query;
	cin>>query;
	while(query--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]<<" "<<sum[u][v]<<endl;
	}
	return 0;
}