class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        long long ans=0;

        int n=nums1.size(),m=nums2.size();

        for(int i=0;i<nums1.size();i++)
        {
          if(m & 1)
          {
            ans^=nums1[i];
          }
        }
        
         for(int i=0;i<nums2.size();i++)
        {
          if(n & 1)
          {
            ans^=nums2[i];
          }
        }

        return ans;

    }
};