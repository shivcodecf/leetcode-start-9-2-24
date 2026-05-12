class Solution {
public:
    vector<vector<int>> dp;

    // Returns length of shortest common supersequence of
    // str1[i:] and str2[j:]
    int solve(string& str1, string& str2, int i, int j) {
        int n = str1.size();
        int m = str2.size();

        // Base cases
        if (i == n) return m - j;
        if (j == m) return n - i;

        // Memoized result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (str1[i] == str2[j]) {
            return dp[i][j] = 1 + solve(str1, str2, i + 1, j + 1);
        }

        // Characters differ
        return dp[i][j] =
            1 + min(
                solve(str1, str2, i + 1, j),   // take str1[i]
                solve(str1, str2, i, j + 1)    // take str2[j]
            );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // Memo table stores only lengths
        dp.assign(n + 1, vector<int>(m + 1, -1));

        // Fill memo table
        solve(str1, str2, 0, 0);

        // Reconstruct answer using dp table
        int i = 0, j = 0;
        string ans = "";

        while (i < n && j < m) {
            // Same character: include once
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            // Take character from str1
            else if (solve(str1, str2, i + 1, j) <=
                     solve(str1, str2, i, j + 1)) {
                ans += str1[i];
                i++;
            }
            // Take character from str2
            else {
                ans += str2[j];
                j++;
            }
        }

        // Append remaining characters
        while (i < n) ans += str1[i++];
        while (j < m) ans += str2[j++];

        return ans;
    }
};