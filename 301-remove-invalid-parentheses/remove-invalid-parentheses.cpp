class Solution {

    bool isValid(string& s1) {
        int count = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '(') {
                count++;
            } else if (s1[i] == ')') {
                count--;
            }

            if (count < 0) {
                return false;
            }
        }

        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;

        queue<string> q;

        q.push(s);

        
            bool flag = false;

        visited.insert(s);

        while (!q.empty()) {

            int n = q.size();


            

           
               string s1 = q.front();

                q.pop();

                

                if (isValid(s1)) {
                    ans.push_back(s1);
                    flag = true;
                }
            
            

            if (flag) {
                continue;
            }

            for (int i = 0; i < s1.size(); i++) {

                string next = "";

                if (s1[i] == '(' || s1[i] == ')') {
                    next = s1.substr(0, i) + s1.substr(i + 1);
                }

                if (!visited.count(next) && next.size()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
            
        }

        if(ans.size())

        return ans;

        ans.push_back("");

        return ans;
    }
};