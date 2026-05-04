class Solution {
    unordered_set<string> st;
    vector<int> dp;

    int solve(string& s, int ind) {
        if (ind >= s.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int ans = INT_MAX;
        string curr = "";

        for (int i = ind; i < s.size(); i++) {
            curr += s[i];

            // If substring exists in dictionary → no extra cost
            if (st.count(curr)) {
                ans = min(ans, solve(s, i + 1));
            } else {
                // Otherwise count as extra character
                ans = min(ans, (i - ind + 1) + solve(s, i + 1));
            }
        }

        // n*(n) = n*n  // in case of dp only

        return dp[ind] = ans;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for (auto& word : dictionary) {
            st.insert(word);
        }

        int n = s.size();
        dp.resize(n, -1);

        return solve(s, 0);
    }
};