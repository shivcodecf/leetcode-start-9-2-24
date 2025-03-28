class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort the input array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
           
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int left = i + 1, right = n - 1;

            while (left < right) {

                int sum = nums[left] + nums[right];

                if (sum == target) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                   
                    while (left+1 < right && nums[left] == nums[left + 1]) left++;
                   
                    while (left < right-1 && nums[right] == nums[right - 1]) right--;

                    
                    left++;
                    right--;


                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }

            }
        }

        return ans;
    }
};
