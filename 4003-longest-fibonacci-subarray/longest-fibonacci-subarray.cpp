class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int sum = 0;

        sum=nums[0]+nums[1];

        int ans = 2,c=2;




        for(int i=2;i<n;i++)
        {
          
          if(sum == nums[i])
          { 
            c++;
            ans = max(ans,c);
          }
          else {

             ans = max(ans,c);
             c=2;
             
          }

          sum = nums[i]+nums[i-1];

          

        }

         return ans;



    }
};