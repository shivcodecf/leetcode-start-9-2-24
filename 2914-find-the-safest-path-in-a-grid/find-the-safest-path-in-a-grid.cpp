class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        vector<vector<int>>vi(n,vector<int>(m,-1));

        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,{i,j}});
                    vi[i][j] = 1;
                }
            }
        }

         int dx[] = {0, +1, 0, -1};

         int dy[] = {+1, 0, -1, 0};

         



        while(!q.empty())
        {   

            int dis = q.front().first;

            int x = q.front().second.first;

            int y = q.front().second.second;

            q.pop();

            for(int i=0;i<4;i++)
            {
                int newX = x+dx[i];

                int newY = y+dy[i];

                if(newX>=0 && newX<n && newY>=0 && newY<m && vi[newX][newY]==-1)

                {
                  vi[newX][newY] = 1;
                  v[newX][newY] = dis+1;
                  q.push({dis+1,{newX,newY}});
                }
            }


        }



       
      

    vector<vector<int>> dis(n, vector<int>(m, INT_MIN));

    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({v[0][0], {0, 0}});

    dis[0][0] = v[0][0];

    int ans = INT_MIN;

   
    vector<vector<int>> vis(n, vector<int>(m, -1));

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int man = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (x == n - 1 && y == m - 1) {
            return man;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                vis[newX][newY] == -1) {

                int newSafeness = min(man, v[newX][newY]);

                pq.push({newSafeness, {newX, newY}});
                vis[newX][newY] = 1;
            }
        }
    }

    return -1;
}
}
;