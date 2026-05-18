class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> revAdj(n);
        vector<int> outdegree(n, 0);

        // reverse graph
        for(int i = 0; i < n; i++) {

            outdegree[i] = graph[i].size();

            for(auto neigh : graph[i]) {
                revAdj[neigh].push_back(i);
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

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto prev : revAdj[node]) {

                outdegree[prev]--;

                if(outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};