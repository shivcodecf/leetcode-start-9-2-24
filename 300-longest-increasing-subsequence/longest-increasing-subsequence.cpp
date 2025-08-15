class Solution {
    int dp[2501][2501]; 
    
    int solve(vector<int>& nums, int ind, int prev) {
        if (ind >= nums.size()) return 0;
        
        if (dp[ind][prev + 1] != -1) 
            return dp[ind][prev + 1];
        
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(nums, ind + 1, ind);
        }
        
        int notake = solve(nums, ind + 1, prev);
        
        return dp[ind][prev + 1] = max(take, notake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};
