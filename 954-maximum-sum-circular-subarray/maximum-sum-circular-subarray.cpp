class Solution {
    private: 

    int solve1(vector<int>& nums)
    {  
        int sum=nums[0];
        int maxi=nums[0];
       for(int i=1;i<nums.size();i++)
       {
          sum = min(sum+nums[i],nums[i]);
          maxi = min(sum,maxi);
       }
       return maxi;
    }
    int solve(vector<int>& nums)
    {  
        int sum=nums[0];
        int maxi=nums[0];
       for(int i=1;i<nums.size();i++)
       {
          sum = max(sum+nums[i],nums[i]);
          maxi =max(sum,maxi);
       }
       return maxi;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);

        int maxSum = solve(nums);

        int minSum = solve1(nums);

        int cirsum = sum - minSum;

        if(maxSum>0)  return max(cirsum,maxSum);

        return maxSum;
    }
};