class Solution {
    
    bool check(string & s1)
    {
        int i=0,j=s1.size()-1;

        while(i<j)
        {
            if(s1[i]==s1[j])
            {
                i++;
                j--;
            }
            else {
                return false;
            }
        }

        return true;
    }


public:
    string longestPalindrome(string s) {

        int maxi = INT_MIN;

        string ans = "";
        
        for(int i=0;i<s.size();i++)
        {   
            string s1 = "";

            for(int j=i;j<s.size();j++)
            {
               s1+=s[j];

               if(check(s1))
               {
                
                int x = s1.size();

                if(maxi<x)
                {
                   ans = s1;
                   maxi = x;
                }

               }
            }


        }


        return ans;

        
    }
};