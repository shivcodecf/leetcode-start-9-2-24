class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
       
       sort(nums.begin(),nums.end());

       reverse(nums.begin(),nums.end());

       vector<int>ans;
       
       map<int,int>mp;


       for(int i=0;i<nums.size();i++)
       { 

          if(mp[nums[i]]==0 && k>0)
          {
            ans.push_back(nums[i]);
            
            k--;
          }


          mp[nums[i]]++;

       }

       return ans;


        

    }
};