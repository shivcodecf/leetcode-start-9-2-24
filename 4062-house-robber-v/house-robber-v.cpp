class Solution {

    long long solve(vector<int>& nums, vector<int>& colors, int ind,
              vector<long long>& dp) {
        int n = nums.size();

        if(ind == n-1)
        {
            return nums[ind];
        }

        if (ind >=n) {
            return 0;
        }

        long long take = 0, notake = 0, adjTake = 0;

        if (dp[ind] != -1) {
            return dp[ind];
        }

        notake = solve(nums, colors, ind + 1, dp);

        if (ind < n - 1 && colors[ind] == colors[ind + 1]) {

            take = nums[ind] + solve(nums, colors, ind + 2, dp);

        } else {

            adjTake = nums[ind] + solve(nums, colors, ind + 1, dp);

        }

        return dp[ind] = max(take, max(adjTake, notake));
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        vector<long long> dp(n, -1);

        return solve(nums, colors, 0, dp);
    }
};