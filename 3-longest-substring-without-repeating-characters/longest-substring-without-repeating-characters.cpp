class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0, j = 0;

        unordered_map<char, int> mp;

        int ans = 0;

        int n = s.size();

        while (i < n && j < n) {

            mp[s[j]]++;

            while (i < n && mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};