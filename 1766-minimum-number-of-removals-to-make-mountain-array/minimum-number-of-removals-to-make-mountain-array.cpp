class Solution {
   
 



public:
    int minimumMountainRemovals(vector<int>& nums) {
      int n = nums.size();
    std::vector<int> lis(n, 1), lds(n, 1);

    // Calculate LIS ending at each index
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                lis[i] = std::max(lis[i], lis[j] + 1);
            }
        }
    }

    // Calculate LDS starting from each index
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[i]) {
                lds[i] = std::max(lds[i], lds[j] + 1);
            }
        }
    }

    int max_mountain_len = 0;

    // Calculate maximum mountain length
    for (int i = 1; i < n - 1; ++i) {
        if (lis[i] > 1 && lds[i] > 1) { // Valid peak
            max_mountain_len = std::max(max_mountain_len, lis[i] + lds[i] - 1);
        }
    }

    return n - max_mountain_len;

    }
};