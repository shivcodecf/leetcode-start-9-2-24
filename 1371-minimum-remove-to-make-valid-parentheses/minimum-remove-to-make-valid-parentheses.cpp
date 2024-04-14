class Solution {
public:
    string minRemoveToMakeValid(string s) {

       stack<int>st;
       map<int,int>mp;

       for(int i=0;i<s.size();i++)
       {


        if(s[i]=='(')
        {
            st.push(i);
        }
        else if(s[i]==')')
        {
            if(!st.empty())
            {
              st.pop();
            }
            else
            {
              mp[i]++;
            }
           
        }


       }

       while(!st.empty())
       {
         mp[st.top()]++;
         st.pop();
       }
       string ans="";

       for(int i=0;i<s.size();i++)
       {
          if(mp[i]==0)
          {
            ans+=s[i];
          }
       }
       return ans;

    }
};