class Solution {
public:
    int solve(int n, int k, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0 && ind == 0) {
            return 1;
        }
        if (target <= 0 || ind == 0) {
            return 0;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += solve(n, k, ind - 1, target - i, dp);
            ans %= 1000000007;  // To handle large numbers and prevent overflow
        }

        dp[ind][target] = ans;
        return dp[ind][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, n, target, dp);
    }
};
