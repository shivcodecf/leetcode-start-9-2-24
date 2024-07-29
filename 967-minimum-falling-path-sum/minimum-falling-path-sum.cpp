class Solution {
private:
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return INT_MAX; // Return a large value to indicate an invalid path
        }
        if (i == n - 1) {
            return dp[i][j] = matrix[i][j]; // Base case: last row
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j]; // Return cached result
        }

        // Calculate the minimum falling path sum for all possible moves
        int downLeft = solve(matrix, i + 1, j - 1, n, m, dp);
        int down = solve(matrix, i + 1, j, n, m, dp);
        int downRight = solve(matrix, i + 1, j + 1, n, m, dp);

        dp[i][j] = matrix[i][j] + min({downLeft, down, downRight});
        return dp[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); // Initialize dp table with -1

        for (int j = 0; j < m; j++) {
            mini = min(solve(matrix, 0, j, n, m, dp), mini);
        }

        return mini;
    }
};
