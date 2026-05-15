class Solution {
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, vector<int>& temp, int sum,
               int ind) {

        int n = candidates.size();

        if (sum > target) {
            return;
        }

        if (ind >= n) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        if (sum == target) {
            ans.push_back(temp);
            return;
        }
       

        temp.push_back(candidates[ind]);
        

        solve(candidates, target, temp, sum + candidates[ind], ind);

        temp.pop_back();

        // sum += candidates[ind];

        // Skip all duplicates of the current value
        while (ind + 1 < candidates.size() &&
               candidates[ind] == candidates[ind + 1]) {
            ind++;
        }

        

        solve(candidates, target, temp, sum, ind + 1);

        // sum -= candidates[ind];

        // solve(candidates, target, temp, sum + candidates[ind], ind + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, temp, 0, 0);

        return ans;
    }
};