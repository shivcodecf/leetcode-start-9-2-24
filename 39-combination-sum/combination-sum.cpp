class Solution {

    vector<vector<int>>ans;

     void solve(vector<int>& candidates, int n, vector<int>& v, int target, int sum,
          int ind) {

        if (sum == target) {
            ans.push_back(v);
            return;
        }

        if (ind >= n || sum > target) {
            return;
        }

        v.push_back(candidates[ind]);

        solve(candidates, n, v, target, sum+candidates[ind], ind);

        v.pop_back();

        solve(candidates, n, v, target, sum, ind + 1);


    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> v;

        int n = candidates.size();

        sort(candidates.begin(), candidates.end());

        solve(candidates, n, v, target, 0, 0);

        return ans;
    }
};