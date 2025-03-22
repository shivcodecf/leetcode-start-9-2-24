class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT_MIN,sum=0;

        
        for(int i=0;i<nums.size();i++)
        { 

         if(sum+nums[i]>=0)
         {  

            sum+=nums[i];
            ans = max(ans,sum);

         }
         
         else {

            ans = max(ans,sum+nums[i]);

            sum = 0;

         }
          
          
        }

        return ans;

    }
};