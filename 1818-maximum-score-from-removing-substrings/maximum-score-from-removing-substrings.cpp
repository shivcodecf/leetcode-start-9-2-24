#include <stack>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<int> st; // Stack to store indices
        int ans = 0;

        map<int, int> mp;

        char start, end;

        if (x >= y) {
            start = 'a';
            end = 'b';
        } else {
            start = 'b';
            end = 'a';
           
        }

        // First pass to remove pairs of start and end characters
        for (int i = 0; i < s.size(); ++i) {


            if (s[i] != end) {
                st.push(i);

            } else  {
                if (st.size() && s[st.top()] == start && s[i]==end) {
                    ans++;
                    mp[st.top()]++;
                    mp[i]++;
                    st.pop();
                
            }

            else {
                st.push(i);
            }
        }


        }

        long long res = ans*max(x,y);

        cout <<res<<endl;
       

        // Create a new string without the removed pairs
        string s1 = "";

      
        for (int i = 0; i < s.size(); i++) {

            if (mp.find(i)==mp.end()) {
                s1 += s[i];
            }

        }

        cout <<s1<<endl;
         
        
        ans = 0;
        int ans1 = 0;

        stack<char> st1;
        // Second pass to remove pairs of 'a' and 'b' in the remaining string
        for (char c : s1) {

            if (c == 'a') {
                if (!st1.empty() && st1.top() == 'b') {
                    st1.pop();
                    ans1++;
                } else {
                    st1.push(c);
                }
            } else if (c == 'b') {
                if (!st1.empty() && st1.top() == 'a') {
                    st1.pop();
                    ans++;
                } else {
                    st1.push(c);
                }
            }
            else{
                st1.push(c);
            }


        }

        res += ans * x + ans1*y;
        return res;
    }
};
