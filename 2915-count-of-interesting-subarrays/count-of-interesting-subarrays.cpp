class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0 , pre_sum = 0;
        unordered_map<long long , int> mp;

        int sum=0;

        mp[0]++;

        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]%modulo==k)
          {
            sum++;
          }

          
             
           int x = (sum-k+modulo)%modulo;

          if(mp.find((sum-k+modulo)%modulo)!=mp.end())
          {
            ans+=mp[x];
          }

          mp[sum%modulo]++;


        }


        
        


        return ans;
    }
};