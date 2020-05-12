#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 1000005
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

struct query
{
	int ul,l,r,index;
};

bool cmp(query a,query b)
{
	if(a.ul!=b.ul)
		return a.ul<b.ul;
	else
		return a.r<b.r;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+1]={0};
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	int qq;
	cin>>qq;
	int final[qq];
	query q[qq];
	int rootn=sqrt(n);
	for(int i=0;i<qq;i++)
	{
		scanf("%d",&q[i].l);
		scanf("%d",&q[i].r);
		q[i].index=i;
		q[i].ul=q[i].l/rootn;
	}
	sort(q,q+qq,cmp);
	int freq[MAX]={0},left=1,right=1;
	freq[arr[1]]++;
	int cnt=1;
	for(int i=0;i<qq;i++)
	{
		while(q[i].l<left)
		{
			left--;
			freq[arr[left]]++;
			if(freq[arr[left]]==1)
				cnt++;
		}

		while(q[i].l>left)
		{
			freq[arr[left]]--;
			if(freq[arr[left]]==0)
				cnt--;
			left++;
		}

		while(q[i].r>right)
		{
			right++;
			freq[arr[right]]++;
			if(freq[arr[right]]==1)
				cnt++;
		}		

		while(q[i].r<right)
		{
			freq[arr[right]]--;
			if(freq[arr[right]]==0)
				cnt--;
			right--;
		}
		final[q[i].index]=cnt;
	}
	for(int i=0;i<qq;i++)
		printf("%d\n",final[i]);
	return 0;
}