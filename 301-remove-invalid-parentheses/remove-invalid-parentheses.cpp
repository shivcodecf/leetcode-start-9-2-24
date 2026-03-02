class Solution {

    bool isValid(string &s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
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
        visited.insert(s);

        while (!q.empty()) {

            int size = q.size();
            bool found = false;

            for (int i = 0; i < size; i++) {

                string curr = q.front();
                
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int j = 0; j < curr.size(); j++) {

                    if (curr[j] != '(' && curr[j] != ')')
                        continue;

                    string next =
                        curr.substr(0, j) + curr.substr(j + 1);

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) break;
        }

        if (ans.empty()) ans.push_back("");

        return ans;
    }
};