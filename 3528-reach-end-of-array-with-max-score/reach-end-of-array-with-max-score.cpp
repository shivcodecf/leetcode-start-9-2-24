class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        
         
         int n=nums.size();

         long long maxi = nums[0],ind=0,ans=0;

         for(int i=1;i<n;i++)
         {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                ans+=(i-ind)*nums[ind];
                ind=i;
            }
         }

         ans+=nums[ind]*((n-1)-ind);

         return ans;





    }
};