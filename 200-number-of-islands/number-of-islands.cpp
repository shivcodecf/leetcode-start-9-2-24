class Solution {
  
  private:

  void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        queue<pair<int,int>>q;
        
        vis[i][j] =1;
        
        int n=grid.size(),m=grid[0].size();
        
        q.push({i,j});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int x=-1;x<=1;x++)
            {
                for(int y=-1;y<=1;y++)
                {    

                    if( (x==1 && y==0) || (x==0 && y==1) || (x==-1 && y==0 ) || (x==0 && y==-1 ) )
                    { 

                     int nrow = row + x;
                    
                    int ncol = col + y;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !(vis[nrow][ncol]))
                    {
                       vis[nrow][ncol] =1;
                       
                       q.push({nrow,ncol});
                    }


                    
                    }

                    
                }

            }
            
            
        }
        
        
        
        
        
        
        
        
        
    }
    



public:
    int numIslands(vector<vector<char>>& grid) {
        

        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {    
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }


        return cnt;

    }
};