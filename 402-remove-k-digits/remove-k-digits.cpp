class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n=num.length();
        if(k==n)return "0";
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++)
        {   

            while(!st.empty() && k>0 && st.top()>num[i])
            {
                st.pop();

                k--;
            }

            st.push(num[i]);

            // if(st.size()==1&&st.top()=='0')st.pop();
        }

        while(k  && !st.empty())
        { 

            k--;

            st.pop();

        }
        while(!st.empty())
        {  

            ans+=st.top();

            st.pop();

        }

        string res="";
        int flag=0;

        int m=ans.size(),ind = -1;

        for(int i=ans.size()-1;i>=0;i--)
        {  

          if(ans[i]=='0' && flag==0)
          {
            continue;
          }

          else {
          
          ind = i;
          break;
            

          }


        }

        for(int i=0;i<=ind;i++)
        {
            res+=ans[i];
        }

        if(res=="")return "0";
        else reverse(res.begin(),res.end());
        return res;
    }
};