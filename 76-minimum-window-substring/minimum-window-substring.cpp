class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;

        for(char c : t)
            need[c]++;

        int count = 0;
        int left = 0;

        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < s.size(); right++) {

            need[s[right]]--;

            if(need[s[right]] >= 0)
                count++;

            while(count == t.size()) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;

                if(need[s[left]] > 0)
                    count--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};