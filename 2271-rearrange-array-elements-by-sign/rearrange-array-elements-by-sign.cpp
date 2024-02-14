class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v1,v2,result;
        int n=nums.size();
      
     for(int i=0;i<n;i++ )
     {  
         if(nums[i]>0)
         v1.push_back(nums[i]);
     }
     for(int i=0;i<n;i++ )
     {  
         if(nums[i]<0)
         v2.push_back(nums[i]);
     }
     for(int i=0;i<v1.size();i++)
     {
        result.push_back(v1[i]);
        result.push_back(v2[i]);
     }
     
     return result;


    }
};