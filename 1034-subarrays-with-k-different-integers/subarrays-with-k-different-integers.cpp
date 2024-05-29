class Solution {
public:
    int f(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
            int cur=nums[r];
            mp[cur]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
public:
      int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
      }  
};