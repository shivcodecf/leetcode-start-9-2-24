class Solution {
    int solve(vector<int>& nums,int ind,int prev,vector<vector<int>>& dp)
    {   
        int n = nums.size();

        if(ind>=n)
        {
            return 0;
        }

        int take = INT_MIN , notake = INT_MIN;

        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }

        if(prev == -1 || nums[ind]>nums[prev])
        {
           take = 1+solve(nums,ind+1,ind,dp);
        }

        notake = solve(nums,ind+1,prev,dp);

        return dp[ind][prev+1] =  max(take,notake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(nums,0,-1,dp);
        
    }
};