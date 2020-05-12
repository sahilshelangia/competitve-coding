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
	int n,q;
	cin>>n>>q;
	set<int>s;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i])
			s.insert(i);
	}
	while(q--){
		int type,x;
		cin>>type>>x;
		if(type==0){
			set<int>:: iterator it=s.lower_bound(x);
			if(it==s.begin())
				cout<<-1<<" ";
			else{
				it--;
				cout<<*it<<" ";
				it++;
			}

			set<int>:: iterator it=s.upper_bound(x);
			if(it==s.end())
				cout<<-1<<endl;
			else{
				cout<<*it<<endl;
			}
		}
		else{
			if(arr[x]==0){
				arr[x]=1;
				s.insert(x);
			}
		}
	}
	return 0;
}