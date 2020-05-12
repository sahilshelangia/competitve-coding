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
	int n,m,t;
	cin>>n>>m>>t;
	char adj[n+1][m+1];
	int status[n+1][m+1],dis[n+1][m+1];
	memset(status,intial,sizeof(status));
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>adj[i][j];

	int sx,sy;
	cin>>sx>>sy;
	queue<PII>q;
	q.push(mp(sx,sy));
	dis[sx][sy]=0;
	status[sx][sy]=visited;
	while(!q.empty()){
		sx=q.front().first;
		sy=q.front().second;
		q.pop();
		int dx=sx+1,dy=sy;
		if(dx<=n&&status[dx][dy]==intial&&adj[dx][dy]=='O'){
			dis[dx][dy]=dis[sx][sy]+1;
			status[dx][dy]=visited;
			q.push(mp(dx,dy));
		}

		dx=sx-1,dy=sy;
		if(dx>0&&status[dx][dy]==intial&&adj[dx][dy]=='O'){
			dis[dx][dy]=dis[sx][sy]+1;
			status[dx][dy]=visited;
			q.push(mp(dx,dy));
		}

		dx=sx,dy=sy+1;
		if(dy<=m&&status[dx][dy]==intial&&adj[dx][dy]=='O'){
			dis[dx][dy]=dis[sx][sy]+1;
			status[dx][dy]=visited;
			q.push(mp(dx,dy));
		}

		dx=sx,dy=sy-1;
		if(dy>0&&status[dx][dy]==intial&&adj[dx][dy]=='O'){
			dis[dx][dy]=dis[sx][sy]+1;
			status[dx][dy]=visited;
			q.push(mp(dx,dy));
		}
	}
	while(t--){
		int dx,dy;
		cin>>dx>>dy;
		cout<<dis[dx][dy]<<endl;
	}
	return 0;
}