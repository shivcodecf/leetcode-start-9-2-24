class Solution {
public:
    char findKthBit(int n, int k) {
        // Start with the first string
        string ans = "0";
        
        for (int i = 1; i < n; ++i) {
            string s1 = ans;
            // Append '1' to the string
            ans += '1';
            // Append the inverted string of s1
            reverse(s1.begin(), s1.end());
            for (char &c : s1) {
                c = (c == '0') ? '1' : '0'; // Flip the bits
            }
            ans += s1; // Concatenate the inverted string
        }
        
        return ans[k - 1]; // Return the k-th bit (1-indexed)
    }
};
