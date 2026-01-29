class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<vector<pair<int, float>>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<float> dis(n + 1, 0.0f);
        dis[start_node] = 1.0f;

        priority_queue<pair<float, int>> pq;
        pq.push({1.0f, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node)
                return prob;

            for (auto [next, succ] : adj[node]) {
                if (prob * succ > dis[next]) {
                    dis[next] = prob * succ;
                    pq.push({dis[next], next});
                }
            }
        }

        return 0.0f;
    }
};