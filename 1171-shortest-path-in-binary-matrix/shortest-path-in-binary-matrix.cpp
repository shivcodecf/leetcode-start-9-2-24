class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int, pair<int, int>>> q;

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));

        if(grid[0][0]==1)
        {
            return -1;
        }

        q.push({1, {0, 0}});

        while (!q.empty()) {

            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return dis;
            }

            if (x + 1 < n && grid[x + 1][y] == 0 && vis[x + 1][y] == -1) {
                vis[x + 1][y] = 1;
                q.push({dis + 1, {x + 1, y}});
            }

            if (y + 1 < m && grid[x][y + 1] == 0 && vis[x][y + 1] == -1) {
                vis[x][y + 1] = 1;
                q.push({dis + 1, {x, y + 1}});
            }

            if (y - 1 >= 0 && grid[x][y - 1] == 0 && vis[x][y - 1] == -1) {
                vis[x][y - 1] = 1;
                q.push({dis + 1, {x, y - 1}});
            }

            if (x - 1 >= 0 && grid[x - 1][y] == 0 && vis[x - 1][y] == -1) {
                vis[x - 1][y] = 1;
                q.push({dis + 1, {x - 1, y}});
            }

            if (x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == 0 &&
                vis[x - 1][y - 1] == -1) {

                vis[x - 1][y - 1] = 1;
                q.push({dis + 1, {x - 1, y - 1}});
            }

            // if (x - 1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == 0 &&
            //     vis[x - 1][y - 1] == 0) {
            //     q.push({dis + 1, {x - 1, y - 1}});
            // }

            if (x + 1 < n && y + 1 < m && grid[x + 1][y + 1] == 0 &&
                vis[x + 1][y + 1] == -1) {

                vis[x + 1][y + 1] = 1;
                q.push({dis + 1, {x + 1, y + 1}});
            }

            if (x - 1 >= 0 && y + 1 < m && grid[x - 1][y + 1] == 0 &&
                vis[x - 1][y + 1] == -1) {

                vis[x - 1][y + 1] = 1;
                q.push({dis + 1, {x - 1, y + 1}});
            }

            if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == 0 &&
                vis[x + 1][y - 1] == -1) {

                vis[x + 1][y - 1] = 1;

                q.push({dis + 1, {x + 1, y - 1}});

            }
        }

        return -1;
    }
};