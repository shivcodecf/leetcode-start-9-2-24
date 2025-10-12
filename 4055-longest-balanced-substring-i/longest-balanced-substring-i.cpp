class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        // Try for every possible unique char count
        for (int uniq = 1; uniq <= 26; uniq++) {
            // sliding window
            for (int i = 0; i < n; i++) {
                vector<int> freq(26, 0);
                int distinct = 0;

                for (int j = i; j < n; j++) {
                    int idx = s[j] - 'a';
                    if (freq[idx] == 0) distinct++;
                    freq[idx]++;

                    if (distinct > uniq) break;

                    int len = j - i + 1;
                    if (distinct == uniq && len % uniq == 0) {
                        int need = len / uniq;
                        bool ok = true;
                        for (int f : freq) {
                            if (f != 0 && f != need) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) ans = max(ans, len);
                    }
                }
            }
        }
        return ans;
    }
};
