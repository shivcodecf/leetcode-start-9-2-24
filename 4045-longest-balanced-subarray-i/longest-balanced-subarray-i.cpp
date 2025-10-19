class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int ans =0;

        for(int i=0;i<nums.size();i++)
        {   
             
             map<int,int>mp1,mp2;

            for(int j=i;j<nums.size();j++)
          {
               if(nums[j] & 1)
               {
                  mp1[nums[j]]++;
               }
               else {
                mp2[nums[j]]++;
               }

               if(mp1.size() == mp2.size() )
               {
                ans = max(ans,j-i+1);
               }

          }

        }

        return ans;

    }
};