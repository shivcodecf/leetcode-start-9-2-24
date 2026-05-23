class Solution {

    int solve(string& str1, string& str2, int i, int j, int n, int m,vector<vector<int>>& dp) {

        // if(i>=n && j>=m)
        // {
        //     return 0;
        // }



        if (i >= n) {
            return m - j;
        }

        if (j >= m) {
            return n - i;
        }

        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }

        int equal = INT_MAX, take1 = INT_MAX, take2 = INT_MAX;

        if (str1[i] == str2[j]) {
            equal = 1 + solve(str1, str2, i + 1, j + 1, n, m,dp);
        } else {
            take1 = 1 + min(solve(str1, str2, i + 1, j, n, m,dp),solve(str1, str2, i, j + 1, n, m,dp));

        }

        return dp[i][j] =  min(equal, take1);
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size(), m = str2.size();

        int i = 0, j = 0;

        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));

        string ans = "";

        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {

                if (solve(str1, str2, i + 1, j, n, m,dp) <
                    solve(str1, str2, i, j + 1, n, m,dp)) {
                    ans += str1[i];
                    i++;
                }

                else {
                    ans += str2[j];
                    j++;
                }
            }
        }

        while(i<n)
        {
            ans+=str1[i];
            i++;
        }

          while(j<m)
        {
            ans+=str2[j];
            j++;
        }

        return ans;
    }
};