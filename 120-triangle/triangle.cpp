class Solution {
    int solve(vector<vector<int>>& triangle, int row, int col,
              vector<vector<int>>& dp) {
        int n = triangle.size();

        // Base case: reached last row
        if (row == n - 1) {
            return triangle[row][col];
        }

        // Memoization
        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        // Two choices:
        // 1. Move to same column in next row
        int down = solve(triangle, row + 1, col, dp);

        // 2. Move to next column in next row
        int diagonal = solve(triangle, row + 1, col + 1, dp);

        // Store and return result
        return dp[row][col] =
            triangle[row][col] + min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Use INT_MAX instead of -1 because triangle values can be negative.
        // If a valid answer equals -1, using -1 as "uncomputed" breaks memoization.
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(triangle, 0, 0, dp);
    }
};