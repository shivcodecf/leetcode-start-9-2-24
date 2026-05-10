class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        int n = grid.size(), m = grid[0].size();

        int zero=0,one=0;

        // vector<vector<int>> temp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if(grid[i][j]==0)
                {
                   zero=1;
                }
                if(grid[i][j]==1)
                {
                   one=1;
                }
                

                if (grid[i][j] == 2) {

                    q.push({i, j});
                    // temp[i][j] = 2;
                }
            }
        }

        if(q.empty())
        {
            if(one>=1)
            {
                return -1;
            }
            return 0;
        }

        int dx[] = {0, +1, 0, -1};

        int dy[] = {-1, 0, +1, 0};

        int ans = 0;

        while (!q.empty()) {

            int l = q.size();

            while (l--) {

                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int newRow = x + dx[i];

                    int newCol = y + dy[i];

                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < m && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
            ans++;
        }

        int flag=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    flag = 1;
                }
            }
        }

        if(flag)
        {
          return -1;
        }

        return ans-1;;

    }
};