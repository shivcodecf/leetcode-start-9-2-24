class Solution {
public:
    int findMaxK(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
          for(int i=0;i<nums.size();i++)
        {
            int x= -nums[i];

            if(mp.find(x)!=mp.end())
            {
                return nums[i];
            }
        }

        return -1;


    }
};