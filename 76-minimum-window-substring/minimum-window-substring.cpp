class Solution {
public:
    string minWindow(string s, string t) {

        map<char, int> mp;

        if(t.size()>s.size())
        {
            return "";
        }

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int n = s.size();

        int i = 0, j = 0;

        int count = t.size();

        int startIndex = -1;

        int minWindow = INT_MAX;

        while (i < n && j < n) {
            if (mp[s[j]] > 0) {

                count--;
            }

            // if(count = 0)
            // {

            // }

            mp[s[j]]--;

            // startIndex = i;

            while (count == 0 && i < n) {
                int windowSize = j-i+1;

                if (minWindow > windowSize) {
                    minWindow = windowSize;
                    startIndex = i;
                }
                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    count++;
                }

                i++;
            }

            j++;
        }

        if(startIndex == -1) return "";

        return s.substr(startIndex, minWindow);
    }
};