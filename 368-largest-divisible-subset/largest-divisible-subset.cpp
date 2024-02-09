#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);         // dp[i] stores the length of the largest
                                      // divisible subset ending at index i
        vector<int> prevIndex(n, -1); // To keep track of the previous index for
                                      // constructing the subset

        int maxLen = 1; // Length of the longest divisible subset
        int endIndex =
            0; // Index of the last element of the longest divisible subset

        // Dynamic Programming - Find the length of the largest divisible subset
        // ending at each index
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                   
                }
                
                 if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        endIndex = i;
                    }
            }
        }

        // Construct the largest divisible subset using the prevIndex array
        vector<int> result;
        while (endIndex != -1) {
            result.push_back(nums[endIndex]);
            endIndex = prevIndex[endIndex];
        }

        return result;
    }
};
