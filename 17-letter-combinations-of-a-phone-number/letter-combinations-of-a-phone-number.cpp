class Solution {
    
    void solve(string& s, int ind, string s1, map<int, vector<char>>& mp, vector<string>& ans) {
        if (ind >= s.size()) {
            ans.push_back(s1);
            return;
        }

        int x = s[ind] - '0';  // Extract the digit from string
        for (auto it : mp[x]) {
            s1 += it;  // Add current letter
            solve(s, ind + 1, s1, mp, ans);  // Move to next digit
            s1.pop_back();  // Backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Edge case: empty input

        map<int, vector<char>> mp = {
            {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}
        };

        vector<string> ans;
        solve(digits, 0, "", mp, ans);
        return ans;
    }
};
