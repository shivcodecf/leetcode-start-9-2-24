class Solution {
public: 
   
    int solve(vector<vector<int>>& grid, int i, int r1j, int r2j, vector<vector<vector<int>>>& dp) {
        if (r1j < 0 || r2j < 0 || r1j >= grid[0].size() || r2j >= grid[0].size()) {
            return 0;
        }
       
        if (i == grid.size()) return 0;
        if (dp[i][r1j][r2j] != -1) return dp[i][r1j][r2j];
        
        // Initialize ans for each call
        int ans = 0;
        ans += grid[i][r1j];
        if (r1j != r2j) {
            ans += grid[i][r2j];
        }
       

        int local_maxi = 0; // Initialize local_maxi for each call

        for (int x = r1j - 1; x <= r1j + 1; x++) {
            for (int y = r2j - 1; y <= r2j + 1; y++) {
                local_maxi = max(local_maxi, solve(grid, i + 1, x, y, dp));
            }
        }
        ans += local_maxi;
        return dp[i][r1j][r2j] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m+1, vector<int>(m+1, -1))); // Adjusted the dimensions

        return solve(grid, 0, 0, m - 1, dp);
    }
};
