class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int flag = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int maxi = INT_MAX;
                int minIdx = -1;
               
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] > nums[i]) {
                        maxi = min(maxi, nums[j]);
                        minIdx = j;
                    }
                }

                if (minIdx!=-1) {

                    swap(nums[i], nums[minIdx]);
                    reverse(nums.begin() + i+1, nums.end());
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            reverse(nums.begin(), nums.end());
        }
    }
};