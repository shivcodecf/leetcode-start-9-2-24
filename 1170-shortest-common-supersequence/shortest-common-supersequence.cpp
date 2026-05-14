class Solution {

    int solve(string& str1, string& str2, int i, int j,vector<vector<int>>& dp) {
        int n = str1.size(), m = str2.size();

        if (i >= n) {
            return m - j;
        }
        if (j >= m) {
            return n - i;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int equal = INT_MAX, first = INT_MAX, second = 0;

        if (str1[i] == str2[j]) {
           equal = 1 + solve(str1, str2, i + 1, j + 1,dp);
        } 
        else {

             first = 1 +  min(solve(str1, str2, i + 1, j,dp),solve(str1, str2, i, j + 1,dp));

        }

       
            // second = 1 + solve(str1, str2, i, j + 1,dp);
        

        return dp[i][j] =  min(first,equal);
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // solve(str1, str2, 0, 0,dp);

        int i = 0, j = 0;

        string ans = "";

        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {
                if (solve(str1, str2, i + 1, j,dp) <=
                    solve(str1, str2, i, j + 1,dp)) {
                    ans += str1[i];
                    i++;
                    // j++;
                } else {
                    ans += str2[j];
                    j++;
                    // i++;
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