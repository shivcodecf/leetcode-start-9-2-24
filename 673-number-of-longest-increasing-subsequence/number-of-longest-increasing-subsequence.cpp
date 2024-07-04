#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Memoization table to store the lengths and counts
    vector<vector<pair<int, int>>> dp;

    pair<int, int> solve(vector<int>& nums, int n, int prevIndex, int currIndex) {
        if (currIndex == n) {
            return {0, 1};  // Base case: reached the end, 1 way to form an empty sequence
        }

        if (dp[prevIndex + 1][currIndex].first != -1) {
            return dp[prevIndex + 1][currIndex];  // Return memoized result if available
        }

        // Not take the current element
        pair<int, int> notTake = solve(nums, n, prevIndex, currIndex + 1);
        
        pair<int, int> take = {0, 0};
        // Take the current element if it's greater than the last included element
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            take = solve(nums, n, currIndex, currIndex + 1);
            take.first += 1;  // Increment length as we included the current element
        }

        pair<int, int> result;
        if (take.first > notTake.first) {
            result = take;
        } else if (take.first < notTake.first) {
            result = notTake;
        } else {
            result = {take.first, take.second + notTake.second};  // If lengths are equal, sum the counts
        }

        return dp[prevIndex + 1][currIndex] = result;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Initialize memoization table with -1
        dp = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(n, {-1, -1}));

        pair<int, int> result = solve(nums, n, -1, 0);
        return result.second;
    }
};

// Example usage:
