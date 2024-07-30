class Solution {
public:
    int minimumDeletions(string s) {
        
        stack<char>st;

        st.push(s[0]);
        int ans=0;

        for(int i=1;i<s.size();i++)
        {
            if(st.size() && st.top()=='b' && s[i]=='a')
            {
                st.pop();
                ans++;
            }
            else {
                st.push(s[i]);
            }
        }
        return ans;
    }
};