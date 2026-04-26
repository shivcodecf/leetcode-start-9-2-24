class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        int n = nums.size();

        vector<int>pref1(n,-1),pref2(n,-1);

        int maxi=INT_MIN;


        for(int i=0;i<n;i++)
        {
         maxi = max(maxi,nums[i]);
         pref1[i] = maxi;
        }

        maxi = INT_MIN;

         for(int i=n-1;i>=0;i--)
        {
         maxi = max(maxi,nums[i]);
         pref2[i] = maxi;
        }

        vector<int>ans;


        for(int i=0;i<n;i++)
        {
          if(i==0)
          {
            ans.push_back(nums[i]);
          }
          else if(i==n-1)
          {
            ans.push_back(nums[i]);
          }

          
          else {
            if(pref1[i-1]<nums[i] || pref2[i+1]<nums[i])
            {
                ans.push_back(nums[i]);
            }
          }
        }

        return ans;
        
    }
};