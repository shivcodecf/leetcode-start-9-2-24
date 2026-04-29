class Solution {
    int solve(int n, int m, int x, int y, vector<vector<int>>& dp) {

        if (x == n - 1 && y == m - 1) {
            return 1;
        }

        if(x>=n || y>=m)
        {
            return 0;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int right = 0, down = 0;

        if (x + 1 < n) {
            right = solve(n, m, x + 1, y, dp);
        }

        if (y + 1 < m) {
            down = solve(n, m, x, y + 1, dp);
        }

        return dp[x][y] = right + down;
    }

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, 0, 0, dp);
    }
};