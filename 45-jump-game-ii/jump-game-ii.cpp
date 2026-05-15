class Solution {

    int solve(vector<int>& nums, int ind, int check, vector<vector<int>>& dp) {
        int n = nums.size();

        if (ind == n - 1) {
            return 1;
        }

        if (ind >= n) {
            return INT_MAX;
        }

        if (dp[ind][check] != -1) {
            return dp[ind][check];
        }

        int skip = INT_MAX, jump = INT_MAX, jump1 = INT_MAX;

        if (check - 1 <= 0) {
            jump = 1 + solve(nums, ind + 1, nums[ind], dp);
        } else {
            skip = solve(nums, ind + 1, check - 1, dp);

            jump1 = 1 + solve(nums, ind + 1, nums[ind], dp);
        }

        return dp[ind][check] = min(skip, min(jump, jump1));
    }

public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(mx + 1, -1));

        int ans = solve(nums, 1, nums[0], dp);

        return ans == INT_MAX ? 0 : ans;
    }
};