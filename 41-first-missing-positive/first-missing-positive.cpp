class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

       map<int,int>mp;

       for(int i=0;i<nums.size();i++)
       {
        mp[nums[i]]++;
       } 
       
       int n=nums.size();

       sort(nums.begin(),nums.end());

       for(int i=1;i<=n;i++)
       {
        if(mp.find(i)==mp.end())
        {
            return i;
        }
       }

       return nums[n-1]+1;

      
    }
};