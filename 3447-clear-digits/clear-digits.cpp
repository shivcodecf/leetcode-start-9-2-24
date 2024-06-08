class Solution {
public:
    string clearDigits(string s) {
        char ch,ind=-1;
       stack<char>st;

       for(int i=0;i<s.size();i++)
       {
        if(isalpha(s[i]))
        {
            st.push(s[i]);
        }
        else {
            if(st.size())
            {
                st.pop();
            }
        }
       }

       string ans="";
       
       while(st.size())
       {
         ans+=st.top();
         st.pop();
       }
       reverse(ans.begin(),ans.end());

       return ans;

    }
};