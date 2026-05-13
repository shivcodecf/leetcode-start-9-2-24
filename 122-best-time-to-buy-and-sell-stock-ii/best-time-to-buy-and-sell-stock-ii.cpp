class Solution {
    int solve(vector<int>& prices, int ind, int check,vector<vector<int>>& dp) {
        int n = prices.size();

        if (ind >= n) {
            return 0;
        }

        if(dp[ind][check]!=-1)
        {
            return dp[ind][check];
        }

        int first = 0, second = 0;

        if (check) {
            first = max( (solve(prices, ind + 1, 0,dp) - prices[ind]),
                        solve(prices, ind + 1, 1,dp));
        } else {
            second = max((prices[ind] + solve(prices, ind + 1, 1,dp)),
                         solve(prices, ind + 1, 0,dp));
        }

        return dp[ind][check] =  first+second;
    }

public:
    int maxProfit(vector<int>& prices) { 

        int n = prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return solve(prices, 0, 1,dp); }
};