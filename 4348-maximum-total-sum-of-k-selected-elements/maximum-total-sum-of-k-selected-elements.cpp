class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        int n = nums.size();

        long long ans = 0;

        sort(nums.begin(),nums.end());

        reverse(nums.begin(),nums.end());


        for(int i=0;i<k;i++)
        {
          if(mul>=1)
          {
            ans+= 1LL * nums[i]*mul;
            mul--;
          }
          else {
            ans+=nums[i];
          }

        }

        return ans;
        
    }
};