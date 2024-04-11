class Solution {
public:
    string removeKdigits(string num, int k) {
    

    stack<int>st;

    for(int i=0;i<num.size();i++)
    {
        while(st.size() && st.top()>num[i] && k>0)
        {
            st.pop();
            k--;
        }

        st.push(num[i]);

    }

    while(st.size() && k>0)
    {
        st.pop();
        k--;
    }

      string ans="";

      while(st.size())
      { 
        ans+=st.top();
        st.pop();
      }

      reverse(ans.begin(),ans.end());
      int check=0;
      string res="";


      for(int i=0;i<ans.size();i++)
      {
         if(ans[i]=='0' && check==0)
         {
            continue;
         }
         else {
            res+=ans[i];
            check=1;
         }
      }
     if(res=="")
      return "0";
      return res;

     


    }
};