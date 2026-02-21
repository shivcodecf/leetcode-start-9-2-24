class Solution {
    unordered_set<string> dict;
    vector<int> dp;   // -1 = unvisited, 0 = false, 1 = true

    bool solve(string& s, int ind) {
        if (ind == s.size())
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        string check = "";

        for (int i = ind; i < s.size(); i++) {
            check += s[i];

            if (dict.count(check)) {
                if (solve(s, i + 1))
                    return dp[ind] = 1;
            }
        }

        return dp[ind] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto& word : wordDict)
            dict.insert(word);

        dp.resize(s.size(), -1);

        return solve(s, 0);
    }
};