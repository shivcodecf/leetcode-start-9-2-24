class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<int> pref(n, -1), suff(n, -1);

        // pref[i] = earliest index in t where s[0...i] is matched
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i])
                j++;

            if (j == m)
                break;

            pref[i] = j;
            j++;
        }

        // Already a subsequence
        if (pref[n - 1] != -1)
            return true;

        // suff[i] = latest index in t where s[i...n-1] is matched
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i])
                j--;

            if (j < 0)
                break;

            suff[i] = j;
            j--;
        }

        // Try replacing every position
        for (int k = 0; k < n; k++) {
            int left = (k == 0) ? -1 : pref[k - 1];
            int right = (k == n - 1) ? m : suff[k + 1];

            // Prefix or suffix couldn't be matched
            if (k > 0 && left == -1)
                continue;
            if (k < n - 1 && right == -1)
                continue;

            // Need one position in t strictly between left and right
            if (left < right - 1)
                return true;
        }

        return false;
    }
};