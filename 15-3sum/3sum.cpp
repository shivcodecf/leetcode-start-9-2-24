class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;

        for (int i = 0; i <= nums.size() - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = -nums[i];

            int j = i + 1, k = n - 1;

            int sum = nums[i];

            while (j < k) {
                // sum += nums[j];
                int total = nums[i] + nums[j] + nums[k];

                if (total == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }

                if (total > 0) {
                    k--;
                } else {
                    int take = nums[j];

                    j++;

                    while ( j<n && nums[j - 1] == nums[j]) {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};