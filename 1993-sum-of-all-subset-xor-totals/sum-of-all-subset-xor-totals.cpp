class Solution {
public:    
int ans = 0;

void solve(vector<int>& nums, int ind, vector<int>& v) {    
    if (ind == nums.size()) {    
        int xr = 0;
        for (int i = 0; i < v.size(); i++) {
            xr = xr ^ v[i];
        }
        ans += xr;
        return;
        
    }

    // Include the current element in the subset
    v.push_back(nums[ind]);
    solve(nums, ind + 1, v);
    v.pop_back();

    // Exclude the current element from the subset
    solve(nums, ind + 1, v);
}    

int subsetXORSum(vector<int>& nums) {
    ans = 0;  // Ensure `ans` is reset before calculation
    vector<int> v;
    solve(nums, 0, v);
    return ans;
}

};