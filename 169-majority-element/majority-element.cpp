class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int x=-1,y=0;
        for(auto i:mp){
            if(i.second>x){
            x=i.second;
            y=i.first;
            }
        }
        return y;
    }
};