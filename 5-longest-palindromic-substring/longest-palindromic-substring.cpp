class Solution {
   
   bool isPal(string& s)
   {
    int i=0,j=s.size()-1;

    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
   }

public:
    string longestPalindrome(string s) {

        int ans = 0;
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            string s1 = "";
            for (int j = i; j < s.size(); j++) {
                s1 += s[j];
                if(isPal(s1))
                {
                    if(s1.size()>ans)
                    {
                        res = s1;
                        ans = s1.size();
                    }
                }
            }
        }

        return res;
    }
};