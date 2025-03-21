class Solution {
public:
    int LISUsingMem(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        int include = 0;
        
        if (prev == -1 || nums[prev] < nums[curr]) {

            include = 1 + LISUsingMem(nums, curr, curr + 1, dp);

        }

        int exclude = LISUsingMem(nums, prev, curr + 1, dp);

        dp[prev + 1][curr] = max(include, exclude);

        return dp[prev + 1][curr];
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return LISUsingMem(nums, prev, curr, dp);
    }
};