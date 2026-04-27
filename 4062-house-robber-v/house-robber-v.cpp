class Solution {

    long long solve(vector<int>& nums, vector<int>& colors, int ind,vector<long long>& dp) {
        int n = nums.size();

        if (ind >= n) {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        long long take = LLONG_MIN, take1 = LLONG_MIN;

        long long skip = solve(nums, colors, ind + 1,dp);

        if ((ind == n - 1) || (ind + 1 < n && colors[ind] != colors[ind + 1])) {
            take = nums[ind] + solve(nums, colors, ind + 1,dp);
        }

        if (ind + 1 < n && colors[ind] == colors[ind + 1]) {
            take1 = nums[ind] + solve(nums, colors, ind + 2,dp);
        }

        return dp[ind] =  max(skip, max(take, take1));
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        

        int n = nums.size();

        vector<long long>dp(n,-1);

        return solve(nums, colors, 0,dp);
    }
};