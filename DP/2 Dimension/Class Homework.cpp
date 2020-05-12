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
			string s;
			cin>>s;
			int len=s.length();
			ll val[len+1][len+1];
			for(int i=0;i<len;i++){
				for(int j=i;j<len;j++){
					if(j-i+1>1&&s[i]=='0'){
						val[i][j]=-1;
					}
					else{
						ll ans=0;
						for(int k=i;k<=j;k++){
							ans=ans*10+(s[k]-'0');
							if(ans>1000000000000)
								break;
						}
						if(ans>1000000000000)
							val[i][j]=-1;
						else
							val[i][j]=ans;
					}
				}
			}

			ll ans=0;
			bool flag=false;
			for(int i=0;i<len;i++){
				for(int j=i+1;j<len;j++){
					for(int k=j+1;k<len-1;k++){
						if(val[0][i]!=-1&&val[i+1][j]!=-1&&val[j+1][k]!=-1&&val[k+1][len-1]!=-1){
							ans=max(ans,val[0][i]+val[i+1][j]+val[j+1][k]+val[k+1][len-1]);
							flag=true;
						}
					}
				}
			}
			if(flag)
				cout<<ans<<endl;
			else
				cout<<"unlucky"<<endl;
		}
		return 0;
	}