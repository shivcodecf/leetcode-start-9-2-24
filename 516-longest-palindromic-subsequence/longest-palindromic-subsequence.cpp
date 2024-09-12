class Solution {
public:
    // Recursive function to find the longest palindromic subsequence
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        // Base cases
        if (i > j) return 0; // If i crosses j, no valid subsequence exists
        if (i == j) return 1; // A single character is a palindrome of length 1

        // If the result is already calculated, return it
        if (dp[i][j] != -1) return dp[i][j];

        // Case 1: If the characters at i and j are the same, include them
        if (s[i] == s[j]) {

            dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
            
        }
        // Case 2: If they are different, take the maximum by either:
        //  - excluding the first character (i+1)
        //  - excluding the last character (j-1)
        else {

            dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));

        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // Create a DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // Call the recursive function
        return solve(s, 0, n - 1, dp);
    }
};
