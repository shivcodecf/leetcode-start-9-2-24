#include <vector>
#include <algorithm>
#include <climits>

class Solution {
    std::vector<std::vector<int>> memo;

    int solve(int m, int paste, int copy) {
        if (paste == m) {
            return 0; // No additional steps needed if we have exactly m characters
        }

        if (paste > m) {
            return 1000; // Invalid state, can't exceed m characters
        }

        if (memo[paste][copy] != -1) {
            return memo[paste][copy]; // Return cached result
        }

        // int cpy = INT_MAX;
        // int pas = INT_MAX;

        // If copy is not zero, we can use the copy-paste operation
       
            int cpy = 2 + solve(m, paste+paste, paste); // Perform copy operation
        

        // If copy is not zero, we can paste the copied characters
       
            int pas = 1 + solve(m, paste + copy, copy); // Perform paste operation
        

        memo[paste][copy] = std::min(cpy, pas); // Store the minimum result
        return memo[paste][copy];
    }

public:
    int minSteps(int n) {

        if(n<=1) return 0;
        memo.assign(n + 1, std::vector<int>(n + 1, -1)); // Initialize memoization table
        return 1+solve(n, 1, 1); // Start with 1 character and no copy
    }
};
