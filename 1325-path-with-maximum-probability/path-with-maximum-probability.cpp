class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        unordered_map<int, vector<pair<int, double>>> adj;

        int m = edges.size();

        int i = 0;

        for (auto& it : edges) {
            int x = it[0];
            int y = it[1];
            adj[x].push_back({y, succProb[i]});
            adj[y].push_back({x, succProb[i]});
            i++;
        }

        priority_queue<pair<double, int>> pq;

        vector<double> vis(n, INT_MIN);

        pq.push({1, start_node});

        vis[start_node] = 1;

        while (!pq.empty()) {

            double dis = pq.top().first;
            int x = pq.top().second;
            pq.pop();

            for (auto& v : adj[x]) {

                if (dis * v.second > vis[v.first]) {

                    vis[v.first] = dis * v.second;
                    pq.push({dis * v.second, v.first});

                }
            }
        }

        return vis[end_node] == INT_MIN ? 0.00000 : vis[end_node] ;
    }
};