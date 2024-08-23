class Solution {
private:
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& vis) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0 || vis[i][j] == 1) {
            return 0;
        }

        // Include the gold in the current cell
        int currentGold = grid[i][j];
        vis[i][j] = 1;  // Mark the current cell as visited

        // Explore all four directions
        int right = currentGold+solve(grid, n, m, i, j + 1, vis);
        int left = currentGold+solve(grid, n, m, i, j - 1, vis);
        int down = currentGold+solve(grid, n, m, i + 1, j, vis);
        int up = currentGold+solve(grid, n, m, i - 1, j, vis);

        // Backtrack by unmarking the cell
        vis[i][j] = 0;

        // Return the maximum gold collected from any direction, including the current cell
        return   max({right, left, down, up});
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

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
