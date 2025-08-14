class Solution {
    
    int solve(vector<int>& nums,int ind,vector<int>& dp)
    {  
           
       if (ind >= nums.size()) return 0;

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int take = nums[ind]+solve(nums,ind+2,dp);

        int notake = solve(nums,ind+1,dp);

        return dp[ind] =  max(take,notake);

    }

public:
    int rob(vector<int>& nums) {

        int n= nums.size();

        vector<int>dp(n,-1);
        
        return solve(nums,0,dp);

    }
};