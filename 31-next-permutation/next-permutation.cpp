class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n=nums.size();

        int gola_idx = -1;
        
      for(int i=n-1;i>0;i--)
      {
        if(nums[i]>nums[i-1])
        {
            gola_idx = i-1;
            break;
        }
      }

      int swap_idx = -1;

      if(gola_idx!=-1)
      {
        for(int i=n-1;i>gola_idx;i--)
      {
        if(nums[i]>nums[gola_idx])
        {
         swap_idx = i;
         break;
        }
      }

      swap(nums[gola_idx],nums[swap_idx]);
      }

      

      reverse(nums.begin()+gola_idx+1,nums.end());
     


    }
};