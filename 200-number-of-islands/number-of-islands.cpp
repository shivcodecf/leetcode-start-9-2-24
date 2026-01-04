class Solution {
      
      void dfs(vector<vector<char>>& grid ,vector<vector<int>>& vis,int x, int y )
      { 

          int n = grid.size(),m=grid[0].size();

        vis[x][y] = 1;

        int dx[] = {0,1,0,-1};

        int dy[] = {1,0,-1,0};

        for(int i=0;i<4;i++)
        {
            int newR = x+dx[i];

            int newC = y+dy[i];

            if( newR >=0 && newC>=0 && newR <n && newC<m && vis[newR][newC]==-1 && grid[newR][newC]=='1' )
            {
                dfs(grid,vis,newR,newC);
            }
        }




      }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(),m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,-1));

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(vis[i][j]== -1 && grid[i][j]=='1')
               {
                  dfs(grid,vis,i,j);
                  ans++;
               }
            }
        }

        return ans;
        
    }
};