class Solution {
public:
    int minSwaps(string s) {
        
        stack<char>st;

        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                st.push('[');
            }

            else if(s[i]==']')
            {
                if(st.size())
                {
                    st.pop();
                }
                else {
                    ans++;
                    st.push('[');
                }
            }
        }

        return ans;
    }
};