class Solution {
public:
    long long validSubstringCount(string str, string target) {
        int n = str.size();
        
        vector<vector<int>> pre(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {

            pre[i + 1] = pre[i];
            pre[i + 1][str[i] - 'a']++;

        }
        auto cnt = [&] (int l, int r, int idx) {

            return pre[r + 1][idx] - pre[l][idx];

        };
        
        vector<int> req(26, 0);
        for (int i = 0; i < target.size(); i++) req[target[i] - 'a']++;
        
        auto isGood = [&] (int start, int end) {


            for (int charIdx = 0; charIdx < 26; charIdx++) {

                if (cnt(start, end, charIdx) < req[charIdx]) return false;

            }

            return true;

        };
        
        auto findEnd = [&] (int start) {

            int s = start, e = n - 1, res = n;

            while (s <= e) {

                int m = (s + e) / 2;
                if (isGood(start, m)) res = m, e = m - 1;
                else s = m + 1;
                
            }

            return res;
        };
        
        long long ans = 0;
        
        for (int s = 0; s < n; s++) {


            int e = findEnd(s);
            ans += n - e;


        }
        
        return ans;
    }
};