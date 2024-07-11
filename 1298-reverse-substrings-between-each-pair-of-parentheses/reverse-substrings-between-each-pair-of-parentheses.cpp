#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseParentheses(string s) {
        
     stack<int> st;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int start = st.top();
            st.pop();
            reverse(s.begin() + start + 1, s.begin() + i);
        }
    }

    string ans;
    for (char c : s) {
        if (isalpha(c)) {
            ans += c;
        }
    }

    return ans;


    }
};