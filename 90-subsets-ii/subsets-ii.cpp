class Solution {
      
      vector<vector<int>>ans;
      
      void solve(vector<int>& nums,int ind, vector<int>& v)
      { 

       if(nums.size()<=ind)
       { 
        ans.push_back(v);

        return;
       }

       ans.push_back(v);



       for(int i=ind;i<nums.size();i++)
       { 

        if(i>ind && nums[i]==nums[i-1]) continue;
        v.push_back(nums[i]);
        solve(nums,i+1,v);
        v.pop_back();
       }

      }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int>v;
        
        solve(nums,0,v);

        return ans;

    }
};