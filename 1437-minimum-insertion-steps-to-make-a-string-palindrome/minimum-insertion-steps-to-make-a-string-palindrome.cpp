class Solution {

    int solve(string& s, int i, int j, vector<vector<int>>& dp) {

        if (i>=j) {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int equal = INT_MAX, first = INT_MAX, second = INT_MAX;

        if (s[i] == s[j]) {
            equal = solve(s, i + 1, j - 1,dp);
        } else {
            first = 1 + solve(s, i + 1, j,dp);
            second = 1 + solve(s, i, j - 1,dp);
        }

        return dp[i][j] =  min(equal, min(first, second));
    }

public:
    int minInsertions(string s) {

        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));

        return 
              solve(s, 0, s.size() - 1,dp); }
};