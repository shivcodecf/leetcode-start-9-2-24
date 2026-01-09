class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;

      int n = grid.size();

      int m = grid[0].size();

      if(grid[0][0]== 1 || grid[n-1][m-1 ]== 1)
      {
        return -1;
      }

      vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));

      dis[0][0] = 0;

      pq.push({0,{0,0}});

      while(!pq.empty())
      { 

        auto it = pq.top();

        pq.pop();

        int path = it.first;

        int row = it.second.first;

        int col = it.second.second;

        if(row == n-1 && col == m-1)
        {
            return path+1;
        }

        int newR = 0, newC = 0;

        if(row-1 >=0 && col-1>=0 && row-1<n && col-1<m && path+1<dis[row-1][col-1] && grid[row-1][col-1]==0)

        {
            dis[row-1][col-1] = path+1;
            pq.push({path+1,{row-1,col-1}});
        }

         if(row-1 >=0 && col+1>=0 && row-1<n && col+1<m && path+1<dis[row-1][col+1] && grid[row-1][col+1]==0)

        {
            dis[row-1][col+1] = path+1;
            pq.push({path+1,{row-1,col+1}});
        }

         if(row+1 >=0 && col+1>=0 && row+1<n && col+1<m && path+1<dis[row+1][col+1] && grid[row+1][col+1]==0)

        {
            dis[row+1][col+1] = path+1;
            pq.push({path+1,{row+1,col+1}});
        }

          if(row+1 >=0 && col-1>=0 && row+1<n && col-1<m && path+1<dis[row+1][col-1] && grid[row+1][col-1]==0)

        {
            dis[row+1][col-1] = path+1;
            pq.push({path+1,{row+1,col-1}});
        }

           if(row >=0 && col+1>=0 && row<n && col+1<m && path+1<dis[row][col+1] && grid[row][col+1]==0 )

        {
            dis[row][col+1] = path+1;
            pq.push({path+1,{row,col+1}});
        }

           if(row +1 >=0 && col>=0 && row+1<n && col<m && path+1<dis[row+1][col] && grid[row+1][col]==0)

        {
            dis[row+1][col] = path+1;
            pq.push({path+1,{row+1,col}});
        }

         if(row >=0 && col-1>=0 && row<n && col-1<m && path+1<dis[row][col-1] && grid[row][col-1]==0)

        {
            dis[row][col-1] = path+1;
            pq.push({path+1,{row,col-1}});
        }

          if(row -1 >=0 && col>=0 && row-1<n && col<m && path+1<dis[row-1][col] && grid[row-1][col]==0)

        {
            dis[row-1][col] = path+1;
            pq.push({path+1,{row-1,col}});
        }

      }

      return -1;








    }
};