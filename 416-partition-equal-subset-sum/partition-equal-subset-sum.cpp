class Solution {
  
  bool solve(vector<int>& nums,int target,int sum,int ind,vector<vector<int>>& dp)
  { 
   
    if(sum == target)
    {
        return true;
    }

    if(sum>target)
    {
        return false;
    }

    if(ind>=nums.size())
    {
        return false;
    }

    if(dp[ind][sum]!=-1)
    {
        return dp[ind][sum];
    }

    bool take = false , notake = false;

    take = solve(nums,target,sum+nums[ind],ind+1,dp);

    notake = solve(nums,target,sum,ind+1,dp);

    return dp[ind][sum] =  take || notake;


  }

public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum & 1)
        {
            return false;
        }

        int target = sum/2;

        int n = nums.size();

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return solve(nums,target,0,0,dp);
        
    }
};