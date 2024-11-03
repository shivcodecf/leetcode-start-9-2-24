class Solution {
public:
    bool rotateString(string s, string goal) {
        

        string temp = "";

        char ch = goal[0];

        for(int i=0;i<s.size();i++)
        { 

            if(s[i]==goal[0])
            { 

                string s1 = s.substr(i,s.size()-i);

                string s2 = s.substr(0,i);

                string ans="";

                 ans = s1+s2;

                cout <<ans;

                if(ans == goal)
                {  
                    
                    return true;

                }


            }

        }

        return false;

    }
};