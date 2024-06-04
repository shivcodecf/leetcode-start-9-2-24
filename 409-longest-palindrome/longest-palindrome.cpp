class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(52, 0); // Vector to store the frequency of both uppercase and lowercase letters

        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                mp[s[i] - 'A']++; // Map uppercase letters to 0-25
            } else if (islower(s[i])) {
                mp[s[i] - 'a' + 26]++; // Map lowercase letters to 26-51
            }
        }

        int ans = 0;
        
        bool hasOdd = false;

        for (int i = 0; i < mp.size(); ++i) {
            if (mp[i] % 2 == 0) {
                ans += mp[i];
            } else {
                ans += mp[i] - 1; // Add the even part
                hasOdd = true;    // Indicate that there's at least one odd count
            }
        }

        if (hasOdd) {
            ans += 1; // Add one to account for a central character in the palindrome
        }

        return ans;
    }
};
