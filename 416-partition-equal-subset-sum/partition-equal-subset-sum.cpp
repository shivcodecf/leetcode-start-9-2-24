class Solution {

    bool solve(vector<int>& nums, int target, int ind, int sum,vector<vector<int>>& dp) {

        if (sum == target) {
            return true;
        }

        if (ind >= nums.size()) {
            return false;
        }

        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }

        sum+=nums[ind];

        int take = solve(nums, target, ind + 1, sum,dp);

        sum-=nums[ind];

        int notake = solve(nums, target, ind + 1, sum,dp);

        return dp[ind][sum] =  take | notake;
    }

public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(),0);

        if (sum % 2) {
            return false;
        }

        int target = sum / 2;

        sum = 0;

        int n= nums.size();

        vector<vector<int>>dp(n+1,vector<int>(target*2,-1));

        return solve(nums, target, 0, sum,dp);

    }
};