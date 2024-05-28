class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int current =0;
        int i =0;
        int maxlength=0;
        for(int j =0;j<s.length();j++)
        {
            current+=abs(s[j]-t[j]);
            while(current>maxCost)
            {
                current -= abs(s[i]-t[i]);
                i++;
            }

            maxlength = max(maxlength, j-i+1);
        }

        return maxlength;
    }
};