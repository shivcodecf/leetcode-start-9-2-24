class Solution {

    vector<vector<int>>ans;
   
   void solve(int n,int k,vector<int>& v,int ind)
   {
       
       if(v.size()==k)
       {
        ans.push_back(v);
        return;
       }

       for(int i=ind;i<=n;i++)
       { 
         v.push_back(i);
         solve(n,k,v,i+1);
         v.pop_back();
       }

       

   }

public:
    vector<vector<int>> combine(int n, int k) {

        vector<int>v;

        solve(n,k,v,1);

        return ans;
        
    }
};