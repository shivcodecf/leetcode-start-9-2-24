class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp; // Vector to store the frequency of both uppercase and lowercase letters

        for (int i = 0; i < s.size(); i++) {
           mp[s[i]]++;
        }

        int ans = 0;

        int  hasOdd = 0 ;

        for(auto i:mp)
        {
            if(i.second%2==0)
            {
                ans+=i.second;
            }
            else{
                hasOdd=1;
                ans+=i.second-1;
            }
        }

        return ans+hasOdd;
    }
};
