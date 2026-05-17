class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y,int& area) {
        vis[x][y] = 1;
        area++;

        int n = grid.size(), m = grid[0].size();

        int dx[] = {0, +1, 0, -1};

        int dy[] = {-1, 0, +1, 0};

        int count = 1;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY < m && newY >= 0 &&
                vis[newX][newY] == -1 && grid[newX][newY] == 1) {

                dfs(grid, vis, newX, newY,area);
            }
        }

       
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int area = 0;
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    dfs(grid, vis, i, j,area);
                    ans = max(area,ans);

                }
            }
        }

        return ans;
    }
};