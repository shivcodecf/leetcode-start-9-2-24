class Solution {
    
    long long solve(int ind, int prevTaken, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp) {
        
        int n = nums.size();
        
        if(ind >= n)
            return 0;

        if(dp[ind][prevTaken] != -1)
            return dp[ind][prevTaken];

        long long notTake = solve(ind + 1, 0, nums, colors, dp);

        long long take = 0;

        if(ind == 0 || !(prevTaken && colors[ind] == colors[ind-1])) {
            take = nums[ind] + solve(ind + 1, 1, nums, colors, dp);
        }

        return dp[ind][prevTaken] = max(take, notTake);
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(0, 0, nums, colors, dp);
    }
};