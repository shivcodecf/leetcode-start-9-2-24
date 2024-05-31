class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xr=0,xr1=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>v;

        for(auto i:mp)
        {
            if(i.second==1)
            {
                v.push_back(i.first);
            }
        }

        // for(int i=0;i<nums.size();i++)
        // {
        //     xr^=nums[i];
        // }
        //  for(int i=0;i<nums.size();i++)
        // {   
        //     xr1^=nums[i];
        // }

        return v;
    }
};