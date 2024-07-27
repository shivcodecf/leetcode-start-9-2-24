class Solution { 
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo) { 
        if (i < 0 || j < 0 || i >= n || j >= m || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int down = 0, right = 0;

        if (i + 1 < n && obstacleGrid[i + 1][j] == 0) {
            down = solve(i + 1, j, n, m, obstacleGrid, memo);
        }

        if (j + 1 < m && obstacleGrid[i][j + 1] == 0) {
            right = solve(i, j + 1, n, m, obstacleGrid, memo);
        }

        return memo[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        vector<vector<int>> memo(n, vector<int>(m, -1));

        return solve(0, 0, n, m, obstacleGrid, memo); 
    }
};
