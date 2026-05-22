class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> revAdj(n);

        vector<int> outdegree(n, 0);

        // reverse graph
        for(int i = 0; i < n; i++) {

            outdegree[i] = graph[i].size();

            for(auto &v : graph[i]) {
                revAdj[v].push_back(i);
            }
        }

        queue<int> q;

        // terminal nodes
        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            ans.push_back(u);

            for(auto &v : revAdj[u]) {

                outdegree[v]--;

                if(outdegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};