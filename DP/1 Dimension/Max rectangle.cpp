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
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int arr[MAX][MAX];

int max_area(int histo[],int m)
{
	int nse[m+1],pse[m+1];
	stack<int>s;
	s.push(1);
	for(int i=2;i<=m;i++)
	{
		while(!s.empty()&&histo[s.top()]>histo[i])
		{
			nse[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		nse[s.top()]=m+1;
		s.pop();
	}


	s.push(m);
	for(int i=m-1;i>=1;i--)
	{
		while(!s.empty()&&histo[s.top()]>histo[i])
		{
			pse[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		pse[s.top()]=0;
		s.pop();
	}

	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int tmp=(nse[i]-pse[i]-1)*histo[i];
		ans=max(tmp,ans);
	}
	return ans;
}
int sum(int n,int m)
{
	int histo[m+1]={0},ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j])
				histo[j]+=arr[i][j];
			else
				histo[j]=0;
		}
		int tmp=max_area(histo,m);
		ans=max(tmp,ans);
	}
	return ans;
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];
		int ans=sum(n,m);
		cout<<ans<<endl;
	}
	return 0;
}