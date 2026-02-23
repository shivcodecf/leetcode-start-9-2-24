class Solution {

    vector<vector<int>>ans;
   
   void solve(int n,int k,vector<int>& v,int ind)
   {  

       

       if(v.size()==k)
       {
        ans.push_back(v);
        return;
       }

        if(ind>n)
       {
        return;
       }
       
      

      

      
         v.push_back(ind);
         solve(n,k,v,ind+1);
         v.pop_back();
         solve(n,k,v,ind+1);
       

       

   }

public:
    vector<vector<int>> combine(int n, int k) {

        vector<int>v;

        solve(n,k,v,1);

        return ans;
        
    }
};