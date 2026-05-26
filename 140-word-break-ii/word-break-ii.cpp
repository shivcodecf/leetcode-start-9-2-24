class Solution {

    vector<string> ans;
    map<string, int> mp;

    void solve(string s, vector<string>& wordDict, int ind, vector<string>& v) {

        if (ind >= s.size()) {
            string sentence = "";

            for (int i = 0; i < v.size(); i++) {
                sentence += v[i];

                if (i != v.size() - 1) {
                    sentence += " ";
                }
            }

            ans.push_back(sentence);

            return;
        }

        string s1 = "";

        for (int i = ind; i < s.size(); i++) {
            s1 += s[i];

            if (mp.find(s1) != mp.end()) {
                v.push_back(s1);
                solve(s, wordDict, i + 1, v);
                v.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]]++;
        }

        vector<string> v;

        solve(s, wordDict, 0, v);

        return ans;
    }
};