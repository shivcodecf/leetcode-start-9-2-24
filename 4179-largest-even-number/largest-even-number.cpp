class Solution {
public:
    string largestEven(string s) {
        
        string s1 = "";

        int flag = 0;


        for(int i=s.size()-1;i>=0;i--)
        {
            if((s[i]-'0')%2==0)
            {
                flag = 1;
            }

            if(flag)
            {
                s1+=s[i];
            }
        }
        
        reverse(s1.begin(),s1.end());
       

         
        return s1;

    }
};