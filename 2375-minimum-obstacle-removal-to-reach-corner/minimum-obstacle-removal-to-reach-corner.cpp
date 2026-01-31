class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        if(grid[0][0]==1)
        {
          pq.push({1,{0,0}});
        }
        else {
          pq.push({0,{0,0}});
        }

        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));

        if(grid[0][0]==1)
        {
            dis[0][0] = 1;
        }
        else {
            dis[0][0] = 0;
        }

        int dx[] = {0,+1,0,-1};

        int dy[] = {+1,0,-1,0};


        while(!pq.empty())
        {
            auto it = pq.top();

            pq.pop();

            int ob = it.first;

            int x = it.second.first;

            int y = it.second.second;

            if(x == n-1 && y == m-1)
            {
                return ob;
            }

            for(int i=0;i<4;i++)
            {
                int newX = x+dx[i];

                int newY = y+dy[i];

                int check=0;

                if(newX>=0 && newX<n && newY>=0 && newY<m)
                {

                    if(grid[newX][newY]==1)
                {
                 check = 1;
                }

                if(ob + check < dis[newX][newY])
                {
                  dis[newX][newY] = check + ob;
                  pq.push({dis[newX][newY],{newX,newY}});
                }

                }

                

            }

            
        }

        return -1;





       
        
    }
};