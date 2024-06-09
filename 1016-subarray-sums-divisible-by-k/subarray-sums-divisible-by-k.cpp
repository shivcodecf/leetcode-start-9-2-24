class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0,sum=0;
        mp[0]=1;
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           int x = sum%k;
           if(x<0){
               x+=k;
           }
           ans+=mp[x];
           mp[x]++;
           
       }
       return ans;
    }
};