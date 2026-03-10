class Solution {

    int solve(vector<int>& nums, int ind,int flag,vector<vector<int>>& dp) {
        int n = nums.size();
        if (flag ==0 && ind >= n-1) {
            return 0;
        }
        if (flag ==1 && ind >= n) {
            return 0;
        }

        if(dp[ind][flag]!=-1)
        {
            return dp[ind][flag];
        }


       

        int skip = INT_MIN , take = INT_MIN;



         skip = solve(nums, ind + 1,flag,dp);

         take = nums[ind] + solve(nums, ind + 2,flag,dp);

        return dp[ind][flag] =  max(skip,take);


    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(nums.size()==1)
        {
            return nums[0];
        }

        

        // vector<int> v;

        // v.push_back(nums[0]);
        // v.push_back(nums[n-1]);

        // for(int i=1;i<n-1;i++)
        // {
        //     v.push_back(nums[i]);
        // }

        vector<vector<int>>dp(n,vector<int>(2,-1));

        return max(solve(nums, 0,0,dp),solve(nums,1,1,dp));
    }
};