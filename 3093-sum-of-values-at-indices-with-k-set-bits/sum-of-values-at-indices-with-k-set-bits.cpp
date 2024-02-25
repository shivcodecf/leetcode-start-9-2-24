class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        vector<int> v;

        for (int i = 0; i < nums.size(); i++) {
            int ans = 0;
            int temp = i; // Store the index in a temporary variable
            while (temp) {
                ans += temp & 1;
                temp = temp >> 1;
            }
            if (ans == k) {
                v.push_back(i);
            }
        }
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            res += nums[v[i]]; // Corrected this line
        }
        return res;
    }
};
