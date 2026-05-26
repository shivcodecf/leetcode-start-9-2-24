class Solution {
public:

    int solve(string& s, int ind, vector<int>& dp)
    {
        int n = s.size();

        if(ind == n)
        {
            return 1;
        }

        if(s[ind] == '0')
        {
            return 0;
        }

        if(dp[ind] != -1)
        {
            return dp[ind];
        }

        int single = solve(s, ind + 1, dp);

        int doub = 0;

        if(ind + 1 < n)
        {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

            if(num >= 10 && num <= 26)
            {
                doub = solve(s, ind + 2, dp);
            }
        }

        return dp[ind] = single + doub;
    }

    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);

        return solve(s, 0, dp);
    }
};