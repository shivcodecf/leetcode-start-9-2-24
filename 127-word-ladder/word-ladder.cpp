class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        queue<string> q;

        q.push(beginWord);

        map<string, int> mp;

        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]]++;
        }

        if (mp.find(endWord) == mp.end()) {
            return 0;
        }

        int ans = 0;

        while (!q.empty()) {
            int n = q.size();

            ans++;

            while (n--) {
                string s = q.front();
                q.pop();

                if (s == endWord) {
                    return ans;
                }

                string s1 = s;

                for (int i = 0; i < s.size(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        s[i] = ch;

                        if (mp.count(s)) {
                            q.push(s);
                            mp.erase(s);
                        }
                    }
                    s = s1;
                }
            }
        }

        return 0;
    }
};