class Solution {

    vector<vector<int>> ans;
    set<vector<int>> st;

    void solve(vector<int>& candidates, vector<int>& v, int target, int ind,
               int sum) {

        int n = candidates.size();

        if (ind >= n || sum>target) {
            return;
        }

      

        if (sum == target) {

                ans.push_back(v);
        

         
            
            return;

        }
        

        sum += candidates[ind];

        v.push_back(candidates[ind]);

        

        solve(candidates, v, target, ind, sum);
          
            v.pop_back();

        sum -= candidates[ind];
       

        solve(candidates, v, target, ind + 1, sum);

       

       
        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> v;

        solve(candidates, v, target, 0, 0);

        return ans;
    }
};