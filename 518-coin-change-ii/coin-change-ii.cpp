class Solution {

    int solve(int ind, int n, int amount, int sum, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind >= n || sum > amount) {
            return 0;
        }

        if (amount == sum) {
            return 1;
        }

        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }

        int take = 0, take1 = 0;

        take = solve(ind, n, amount, sum + coins[ind], coins,dp);

        take1 = solve(ind + 1, n , amount, sum, coins,dp);

        return dp[ind][sum] =  take + take1;
    }

public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(0, n, amount, 0, coins,dp);
    }
};