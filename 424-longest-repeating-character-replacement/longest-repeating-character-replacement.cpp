class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        map<char, int> mp;

        int i = 0, j = 0;

        int ans = 1;

        int maxi = INT_MIN;

        int flag = 0;

        while (i < n && j < n) {
            mp[s[j]]++;

            maxi = max(maxi, mp[s[j]]);

            while (j > i && ((j - i + 1) - maxi) > k) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};