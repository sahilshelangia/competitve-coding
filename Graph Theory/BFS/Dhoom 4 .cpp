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
	ll sampKey,lockValue;
	cin>>sampKey>>lockValue;
	int n;
	cin>>n;
	ll keys[n];
	for(int i=0;i<n;i++)
		cin>>keys[i];
	int status[MAX],timeTaken[MAX];
	memset(status,intial,sizeof(status));
	memset(timeTaken,-1,sizeof(timeTaken));
	timeTaken[sampKey]=0;
	status[sampKey]=waiting;
	queue<int>q;
	q.push(sampKey);
	while(!q.empty()){
		ll u=q.front();
		status[u]=visited;
		q.pop();
		if(u==lockValue)
			break;
		for(int i=0;i<n;i++){
			ll newKey=u*keys[i]%100000;
			if(status[newKey]==intial){
				status[newKey]=waiting;
				q.push(newKey);
				timeTaken[newKey]=timeTaken[u]+1;
			}
		}		
	}
	if(status[lockValue]==intial)
		cout<<-1<<endl;
	else
		cout<<timeTaken[lockValue]<<endl;
	return 0;
}