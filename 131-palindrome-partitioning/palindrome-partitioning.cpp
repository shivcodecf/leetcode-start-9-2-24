class Solution {
    vector<vector<string>> ans;

    bool isPalindrome(string& temp) {

        int i = 0, j = temp.size() - 1;

        while (i < j) {

            if (temp[i] != temp[j]) {
                return false;
            }

            i++;

            j--;
        }

        return true;
    }

    void solve(string& s, int ind, vector<string>& v) {
        if (ind >= s.size()) {
            if (v.size()) {
                ans.push_back(v);
            }
        }

        for (int i = ind; i < s.size(); i++) {

            string temp = s.substr(ind, i-ind+1);

            if (isPalindrome(temp)) {

                v.push_back(temp);

                solve(s, i+1, v);

                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<string> v;

        solve(s, 0, v);

        return ans;
    }
};