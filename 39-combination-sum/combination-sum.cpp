class Solution {

    vector<vector<int>> ans;
    set<vector<int>> st;

    void solve(vector<int>& candidates, vector<int>& v, int target, int ind,
               int sum) {

        int n = candidates.size();

         if (sum == target) {

           
           ans.push_back(v);
           return;
            

        }

        if (ind >= n || sum>target) {
            return;
        }

        
        v.push_back(candidates[ind]);

       

        

        solve(candidates, v, target, ind, sum+candidates[ind]);

         v.pop_back();


        solve(candidates, v, target, ind + 1, sum);

        

       
        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> v;

        solve(candidates, v, target, 0, 0);

        return ans;
    }
};