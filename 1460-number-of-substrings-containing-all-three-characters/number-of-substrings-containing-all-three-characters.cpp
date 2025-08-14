class Solution {
public:
    int numberOfSubstrings(string s) {

        map<char, int> mp;

        int ans = 0, res = 0;

        int j = 0;

        // aaacb

        // abcabc

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;

            if (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {

                res = 0;

                while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                    res++;
                    mp[s[j]]--;
                    j++;
                }

                 ans+=res;  // 1,1

            int check = s.size() - i - 1;  

            ans += res * check; // 2,
            }

           
        }

        return ans;
    }
};