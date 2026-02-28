class Solution {
   
   vector<vector<int>>ans;
   map<int,int>mp;

   void solve(vector<int>& nums,vector<int>& v)
   {  

     int n = nums.size();

     if(v.size()==n)
     {
        ans.push_back(v);
        return;
     }

     for(int i=0;i<n;i++)
     {  

        if(mp.find(nums[i])==mp.end())
        {
             v.push_back(nums[i]);
             mp[nums[i]]++;
             solve(nums,v);
             v.pop_back();
             mp.erase(nums[i]);
        }

        

     }



   }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        

        vector<int>v;

        solve(nums,v);

        return ans;
        
    }
};