class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
         
      sort(nums.begin(),nums.end());

      reverse(nums.begin(),nums.end());

      long long ans=0;

      int x = nums.size()/3;

      for(int i=1;i<nums.size();i+=2)
      {
        ans+=nums[i];
        x--;

        if(x==0)
        {
            break;
        }

      }

      return ans;
         

    }
};