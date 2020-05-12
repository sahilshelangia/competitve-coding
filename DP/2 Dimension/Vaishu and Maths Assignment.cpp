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
int l,n,x,y;


int main()
{
	fast;
	cin>>l>>n>>x>>y;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	queue<int>q;
	q.push(l);
	for(int i=0;i<n-1;i++){
		int sz=q.size();
		set<int>s;
		for(int j=0;j<sz;j++){
			int u=q.front();
			q.pop();
			int tmp=u+arr[i];
			if(tmp>=x&&tmp<=y&&s.find(tmp)==s.end()){
				q.push(tmp);
				s.insert(tmp);
			}
			
			tmp=u-arr[i];
			if(tmp>=x&&tmp<=y&&s.find(tmp)==s.end()){
				q.push(tmp);
				s.insert(tmp);
			}
		}
	}

	std::vector<int> v;
	int sz=q.size();
	for(int j=0;j<sz;j++){
		int u=q.front();
		q.pop();
		int tmp=u+arr[n-1];
		if(tmp>=x&&tmp<=y){
			v.pb(tmp);
		}
		
		tmp=u-arr[n-1];
		if(tmp>=x&&tmp<=y){
			v.pb(tmp);
		}
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	sort(v.begin(),v.end());
	int qq;
	cin>>qq;
	while(qq--){
		char type;
		int val;
		cin>>type>>val;
		if(type=='>'){
			int indx=upper_bound(v.begin(),v.end(),val)-v.begin();
			if(indx<v.size())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			int indx=lower_bound(v.begin(),v.end(),val)-v.begin();
			if(indx==v.size())
				cout<<"NO"<<endl;
			else
			{
				if(v[indx]>=val)
					indx--;
				if(indx>=0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
	}

	return 0;
}