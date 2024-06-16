
#define ll long long
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
      ll currSum=0,ind=0,ans=0;
      ll m=nums.size();

      while(currSum<n)
      {
        if(ind<m && currSum+1>=nums[ind])
        {
            currSum+=nums[ind];
            ind++;
        }
        else {
            ans++;
            currSum+= currSum+1;
        }
      }
      return ans;



    }
};