class Solution {
public:
    // helper function to count vowels in a word
    int solve(string &s1) {
        int c1 = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' ||
                s1[i] == 'o' || s1[i] == 'u') {
                c1++;
            }
        }
        return c1;
    }

    string reverseWords(string s) {
        vector<string> v;
        string s1 = "";
        bool flag = false;

        // split words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                s1 += s[i];
                flag = true;
            } else if (flag) {
                v.push_back(s1);
                s1 = "";
                flag = false;
            }
        }
        if (flag) v.push_back(s1);

        // vowel count of first word
        int c = solve(v[0]);

        vector<string> ans;
        ans.push_back(v[0]);

        // process remaining words
        for (int i = 1; i < v.size(); i++) {
            int cnt = solve(v[i]);
            if (cnt == c) {
                string s2 = v[i];
                reverse(s2.begin(), s2.end());
                ans.push_back(s2);
            } else {
                ans.push_back(v[i]);
            }
        }

        // join words back into a string
        string res = "";
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) res += " ";
            res += ans[i];
        }

        return res;
    }
};
