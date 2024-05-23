class Solution {
   
public: 
 vector<int> v;
    void solve(vector<int>& nums, int k, int ind, vector<int>& v, int& res) {    
    if (ind == nums.size()) {    

        if(v.size()==1)
        {
            res++;
            return;
        } 
        int flag = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (abs(v[i] - v[j]) == k) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag)
            res++;
          return;
    }

    // Include the current element in the subset
    v.push_back(nums[ind]);
    solve(nums, k, ind + 1, v, res);
    v.pop_back();

    // Exclude the current element from the subset
    solve(nums, k, ind + 1, v, res);
}

int beautifulSubsets(vector<int>& nums, int k) {
    int res = 0;
   
    solve(nums, k, 0, v, res);
    return res-1;
}

};