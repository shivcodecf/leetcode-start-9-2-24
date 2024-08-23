class Solution {
private:
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& vis) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j]==0 || vis[i][j]==1) return 0;

        int up = 0, down = 0, right = 0, left = 0;

        vis[i][j] = 1;  

        if (j + 1 < m ) {
            right = grid[i][j] + solve(grid, n, m, i, j + 1, vis);
        }
        if (j - 1 >= 0 ) {
            left = grid[i][j] + solve(grid, n, m, i, j - 1, vis);
        }
        if (i + 1 < n ) {
            down = grid[i][j] + solve(grid, n, m, i + 1, j, vis);
        }
        if (i - 1 >= 0 ) {
            up = grid[i][j] + solve(grid, n, m, i - 1, j, vis);
        }

        vis[i][j] = 0;  // Unmark as visited for backtracking

        // Return the maximum of all four directions
        return max({left, right, up, down});
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;  // Initialize to 0 instead of INT_MIN

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(solve(grid, n, m, i, j, vis), ans);
                }
            }
        }

        return ans;
    }
};
