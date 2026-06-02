class Solution {
    int ans = 0;

    vector<int> free;

    int mini = INT_MAX;

    int solve(vector<vector<int>>& items, int budget, int ind,  vector<vector<int>>& dp)

    {
        int n = items.size();

        if (ind >= n) {
            return budget / mini;
        }

        int take = INT_MIN, notake = INT_MIN;

        if(dp[budget][ind]!=-1)
        {
            return dp[budget][ind];
        }

        if (budget >= items[ind][1]) {

            take = free[ind] + solve(items, budget - items[ind][1], ind + 1,dp);
        }

        notake = solve(items, budget, ind + 1,dp);

        // max(take, notake);

        return dp[budget][ind] =  max(take, notake);
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        // sort(items.begin(), items.end());

        int n = items.size();

        vector<vector<int>>dp(budget+1,vector<int>(n,-1));



        free.resize(n, 0);

        for (int i = 0; i < n; i++) {

            mini = min(mini, items[i][1]);

            for (int j = 0; j < n; j++) {

                if (items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        return solve(items, budget, 0,dp);
    }
};