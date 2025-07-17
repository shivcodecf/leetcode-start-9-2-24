class Solution {
public:
    int f(int i, int buy, vector<int>& prices, int k, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || k == 0)
            return 0;

        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];

        if (buy == 1) {
            dp[i][buy][k] = max(
                -prices[i] + f(i + 1, 0, prices, k, dp),  // buy
                f(i + 1, 1, prices, k, dp)                // skip
            );
        } else {
            dp[i][buy][k] = max(
                prices[i] + f(i + 1, 1, prices, k - 1, dp),  // sell
                f(i + 1, 0, prices, k, dp)                   // skip
            );
        }

        return dp[i][buy][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, prices, k, dp);
    }
};
