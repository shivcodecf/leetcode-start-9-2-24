class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> sus;  // To track suspicious methods
        sus.insert(k);  // Mark method `k` as suspicious
        
        // Build adjacency list (method invocations)
        map<int, vector<int>> mp;
        for (const auto& invocation : invocations) {
            int a = invocation[0];
            int b = invocation[1];
            mp[a].push_back(b);
        }
        
        // BFS to mark all methods that are directly or indirectly invoked by method `k`
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int neighbor : mp[x]) {
                if (!sus.count(neighbor)) {
                    sus.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        // Now check if there's an invalid invocation where a non-suspicious method invokes a suspicious one
        bool invalidInvocation = false;
        for (const auto& invocation : invocations) {
            int a = invocation[0];
            int b = invocation[1];
            if (!sus.count(a) && sus.count(b)) {
                invalidInvocation = true;
                break;
            }
        }

        // If there is an invalid invocation, return a list of all methods
        if (invalidInvocation) {
            vector<int> allMethods(n);
            for (int i = 0; i < n; ++i) {
                allMethods[i] = i;
            }
            return allMethods;
        }

        // Otherwise, return the remaining methods that are not suspicious
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!sus.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
