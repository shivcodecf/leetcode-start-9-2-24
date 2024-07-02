class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

      int n=nums1.size();

      map<int,int>mp;

      for(int i=0;i<n;i++)
      {
        mp[nums1[i]]++;
      } 
       vector<int>ans;

       for(int i=0;i<nums2.size();i++)
      {
        if(mp.count(nums2[i]))
        {
            ans.push_back(nums2[i]);
            mp[nums2[i]]--;
            if(mp[nums2[i]]==0)
            {
                mp.erase(nums2[i]);
            }
        }
      }  

      return ans;

    }
};