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
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int len=s.length();
		int arr[len];
		for(int i=0;i<len;i++)
		{
			if(s[i]=='A')
				arr[i]=-1;
			else
				arr[i]=1;
		}

		bool flag=true;
		for(int i=0;i<len;i++)
		{
			if(arr[i]!='A')
				flag=false;
		}
		if(flag)
		{
			cout<<len-1<<endl;
			continue;
		}
		int left=0,right=0,max_so_far=0,max_ending_here=0,tmp=0;
		for(int i=0;i<len;i++)
		{
			max_ending_here+=arr[i];
			if(max_ending_here<0)
			{
				max_ending_here=0;
				tmp=i+1;
			}
			if(max_ending_here>max_so_far)
			{
				max_so_far=max_ending_here;
				left=tmp;
				right=i;
			}
		}

		// cout<<left<<" "<<right<<endl;
		int ans=0;
		for(int i=left;i<=right;i++)
		{
			arr[i]=arr[i]*-1;
		}
		for(int i=0;i<len;i++)
		{
			if(arr[i]==-1)
				ans++;
		}
		cout<<ans<<endl;

	}
	return 0;
}