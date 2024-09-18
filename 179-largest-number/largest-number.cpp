class Solution {
public:
    string largestNumber(vector<int>& nums) {

        // Custom comparator for sorting numbers based on concatenated results
        auto custom = [](int const& a, int const& b) {  
            string s1 = to_string(a);
            string s2 = to_string(b);

            // Compare concatenated strings
            return s1+s2 > s2+s1;
        };

        // Sort the numbers using the custom comparator
        sort(nums.begin(), nums.end(), custom);

        // If the largest number is "0", return "0" (to avoid multiple leading zeros)
        if (nums[0] == 0) return "0";

        // Build the resulting string by concatenating the numbers
        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};
