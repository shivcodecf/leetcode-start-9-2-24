class Solution {
public:
    bool solve(vector<int>& nums, int ind, int reqSum, int n, int check, vector<vector<int>>& dp) {
        // If the current sum has reached the required sum
        if (check == reqSum) {
            return true;
        }
        // If we have processed all elements or the current sum exceeds the required sum
        if (ind >= n || check > reqSum) {
            return false;
        }
        // If we have already computed the result for this state
        if (dp[ind][check] != -1) {
            return dp[ind][check];
        }

        // Include the current element in the subset
        int take = solve(nums, ind + 1, reqSum, n, check + nums[ind], dp);
        // Exclude the current element from the subset
        int notTake = solve(nums, ind + 1, reqSum, n, check, dp);

        // Store the result in dp array and return
        return dp[ind][check] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            sum += num;
        }

        // If the total sum is odd, we can't partition it into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        int sum1 = sum / 2;

        // Initialize the dp array with -1
        vector<vector<int>> dp(n + 1, vector<int>(sum1 + 1, -1));

        // Start the recursive solution
        return solve(nums, 0, sum1, n, 0, dp);
    }
};
