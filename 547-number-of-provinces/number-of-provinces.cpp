class Solution {

    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis) {
        vis[u] = true;

        for (auto it : adj[u]) {

            if(!vis[it])
            {
                vis[it] = true;
                dfs(adj,it,vis);

            }
            
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        int m = isConnected[0].size();

        vector<bool> vis(n, false);

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < vis.size(); i++) {

            if (!vis[i]) {
                dfs(adj, i, vis);
                count++;
            }
        }

        return count;
    }
};