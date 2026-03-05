class Solution {

    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        int n = word1.size(), m = word2.size();

        if (i >= n || j >= m) {

            if (j <= m - 1) {
                return (m - 1 - j + 1);
            }
             if (i <= n - 1) {
                return (n - 1 - i + 1);
            }


            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int insert = INT_MAX, update = INT_MAX, del = INT_MAX, skip = INT_MAX;

        if (word1[i] == word2[j]) {
            skip = solve(word1, word2, i + 1, j + 1,dp);
        } else {
            insert = 1 + solve(word1, word2, i, j + 1,dp);
            update = 1 + solve(word1, word2, i + 1, j + 1,dp);
            del = 1 + solve(word1, word2, i + 1, j,dp);
        }

        return  dp[i][j] = min({skip, insert, update, del});

    }

public:
    int minDistance(string word1, string word2) {

        int n = word1.size(),m = word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(word1, word2, 0, 0,dp);
    }
};