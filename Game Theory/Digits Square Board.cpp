#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 51
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
int n;

int dp[MAX][MAX][MAX][MAX];
int arr[MAX][MAX],cnt[MAX][MAX];

int grundy(int r1,int r2,int c1,int c2)
{
    if(r1==r2&&c1==c2)
        return 0;

    if(dp[r1][r2][c1][c2]!=-1)
        return dp[r1][r2][c1][c2];
    bool ans=true;
    for(int i=r1;i<r2;i++)
    {
        if(cnt[i][c2]-cnt[r1][c1-1]-cnt[r1-1][c2]+cnt[r1-1][c1-1]>0||cnt[r2][c2]-cnt[i+1][c1-1]-cnt[i][c2]+cnt[i][c1-1]>0)
        {
            ans=ans&&grundy(i+1,r2,c1,c2);
            ans=ans&&grundy(r1,i,c1,c2);
        }
    }

    for(int j=c1;j<c2;j++)
    {
        if(cnt[r2][j]-cnt[r1][c1-1]-cnt[r1-1][j]+cnt[r1-1][c1-1]>0||cnt[r2][c2]-cnt[r1][j]-cnt[r1-1][c2]+cnt[r1-1][j]>0)
        {
            ans=ans&&grundy(r1,r2,c1,j);
            ans=ans&&grundy(r1,r2,j+1,c2);
        }    
    }

    dp[r1][r2][c1][c2]=!ans;
    // cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<":"<<dp[r1][r2][c1][c2]<<" "<<endl;
    return dp[r1][r2][c1][c2];
}

int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX;i++)
            for(int ii=0;ii<MAX;ii++)
                for(int j=0;j<MAX;j++)
                    for(int jj=0;jj<MAX;jj++)
                        dp[i][ii][j][jj]=-1,cnt[i][ii]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]==1||arr[i][j]==4||arr[i][j]==6||arr[i][j]==8||arr[i][j]==9)
                    cnt[i][j]=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1]+1;
                else
                    cnt[i][j]=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1];
            }
        }

        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //         cout<<cnt[i][j]<<" ";
        //     cout<<endl;
        // }

        int ans=grundy(1,n,1,n);
        // cout<<"ANS:"<<ans<<endl;
        if(ans)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
    return 0;
}
