

    #include<bits/stdc++.h>
    using namespace std;
    int n,m;
    int mat[1002][1002];
    int visited[1002][1002];
    int findans(int x, int y)   // counts the number of soldiers in a troop and marks each troop visited in the visited matrix
    {
        visited[x][y] = 1;
        int nodecount = 1;  // counts the number of soldiers in a troop
        queue<pair<int,int> > q;
        q.push(make_pair(x,y));
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = -1 ; i<=1; i++ )
                for(int j = -1; j<=1; j++)
                    if(!visited[x+i][y+j] && mat[x+i][y+j])
                    {
                        nodecount++;
                        q.push(make_pair(x+i,y+j));
                        visited[x+i][y+j] = 1;
                    }
        }
        return nodecount;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&n,&m);
            memset(mat,0,sizeof(mat));
            memset(visited,0,sizeof(visited));
            for(int i = 1; i<=n ; i++)
                for(int j = 1; j<= m; j++)
                    scanf("%d",&mat[i][j]);
            int ans = 0;        // maintains the maximum number of soldiers in any troop
            int counter = 0;    // counts the total number of troops
            for(int i = 1; i <= n ; i++)
                for(int j = 1; j<= m; j++)
                {
                    if(!visited[i][j] && mat[i][j])         // it finds the first 1 in the matrix representing an uncounted troop
                    {
                        ans = max( findans(i,j), ans  );
                        counter++;
                    }
                }
            cout<<counter<<" "<<ans<<endl;
        }
        return 0;
    }

