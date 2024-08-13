class Solution {
   
   private:

    void solve(vector<int>& candidates,int target,int ind,int sum,vector<vector<int>>& ans, vector<int>& v)
   {   

      int n =  candidates.size();

      if(sum>target)
      {
        return;
      }

      if(sum==target)
      {
        ans.push_back(v);
        return;
      }

      if(ind>=n)
      {

              if(sum==target) {

           
            
               ans.push_back(v);
            

            
         
        }

         return;
      } 

      for(int i=ind;i<n;i++)
      { 
            if( candidates[i] > target ) break;

          if( i>ind && candidates[i-1] ==  candidates[i]  && i>0) continue;

        
         v.push_back( candidates[i]);

         solve(candidates,target,i+1,sum + candidates[i],ans,v);

         v.pop_back();


      }


      
    



   }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

       sort(candidates.begin(),candidates.end());

       vector<vector<int>>ans;

       vector<int>v;

       set<vector<int>>st;

       solve(candidates,target,0,0,ans,v); 

       return ans;


    }
};