class Solution {

    void solve(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y) {

    int n = grid.size(), m = grid[0].size();

    vis[y][x] = 1;

    int dx[] = {0, +1, 0, -1};
    int dy[] = {+1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newY >= 0 && newX < m && newY < n &&
            grid[newY][newX] == '1' && vis[newY][newX] == -1) {

            solve(grid, vis, newX, newY);
        }
    }
}

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == -1 && grid[i][j]=='1') {
                    solve(grid, vis, j, i);
                    ans++;
                }
            }
        }

        return ans;
    }
};