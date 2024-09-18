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
        // if (nums[0] == 0) return "0";

        // Build the resulting string by concatenating the numbers
        string ans = "";
        int flag=0;

        for (int num : nums) {

            if(num==0 && flag==0)
            {
                continue;
            }
            else {
               ans += to_string(num);
               flag=1;
             }


            }

            

        
        if(ans=="")
        {
            return "0";
        }
        return ans;
    }
};
