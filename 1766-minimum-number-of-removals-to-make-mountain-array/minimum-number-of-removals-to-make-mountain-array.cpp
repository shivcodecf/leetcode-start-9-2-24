class Solution {
   
   #include <iostream>
#include <vector>
#include <algorithm>

// Recursive function to calculate LIS ending at index i
int lis(int i, const std::vector<int>& nums) {
    if (i == 0) return 1; // Base case: LIS at the first element is itself

    int max_len = 1; // At least the current element is counted as a subsequence
    for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
            max_len = std::max(max_len, 1 + lis(j, nums));
        }
    }
    return max_len;
}

// Recursive function to calculate LDS starting at index i
int lds(int i, const std::vector<int>& nums) {
    if (i == nums.size() - 1) return 1; // Base case: LDS at the last element is itself

    int max_len = 1; // At least the current element is counted as a subsequence
    for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[i]) {
            max_len = std::max(max_len, 1 + lds(j, nums));
        }
    }
    return max_len;
}



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