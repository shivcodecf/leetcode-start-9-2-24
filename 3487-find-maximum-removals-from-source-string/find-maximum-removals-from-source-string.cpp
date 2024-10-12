#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <climits>

class Solution {

    int x = 3e3;
    int dp[3001][3001];  // To safely accommodate indices from 0 to 3000

    int solve(const std::string& source, const std::string& pattern, std::map<int, int>& mp, int i, int j) {
        // Base case: if source is exhausted
        if (i == source.size()) {
            // If pattern is also exhausted, return 0 (no further removals needed)
            if (j == pattern.size()) {
                return 0;
            }
            // Pattern is not fully matched, return a large negative value
            return INT_MIN;
        }

        // If already computed, return memoized result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Case 1: Skip the current character in the source and move on
        int ans = solve(source, pattern, mp, i + 1, j);

        // Case 2: If characters match, try to match further in both source and pattern
        if (j < pattern.size() && source[i] == pattern[j]) {
            ans = std::max(solve(source, pattern, mp, i + 1, j + 1), ans);
        }

        // Case 3: If the index is marked for removal in the map, allow removal and try to solve further
        if (mp.find(i) != mp.end()) {
            ans = std::max(ans, 1 + solve(source, pattern, mp, i + 1, j));
        }

        // Memoize the result and return
        return dp[i][j] = ans;
    }

public:
    int maxRemovals(std::string source, std::string pattern, std::vector<int>& targetIndices) {
        std::map<int, int> mp;

        // Mark indices for removal
        for (int idx : targetIndices) {
            mp[idx]++;
        }

        // Initialize memoization table with -1
        memset(dp, -1, sizeof(dp));

        // Start the recursion from the first character of both strings
        return solve(source, pattern, mp, 0, 0); 
    }
};
