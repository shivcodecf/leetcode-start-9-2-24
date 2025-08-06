class Solution {
    bool solve(vector<int>& nums, int target, int ind, int sum, vector<vector<int>>& dp) {
        if(sum == target) return true;
        if(ind >= nums.size() || sum > target) return false;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        bool take = solve(nums, target, ind + 1, sum + nums[ind], dp);
        bool notake = solve(nums, target, ind + 1, sum, dp);

        return dp[ind][sum] = take || notake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, target, 0, 0, dp);
    }
};
