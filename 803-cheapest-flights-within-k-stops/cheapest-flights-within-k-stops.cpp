class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        // {cost, stops, node}
        pq.push({0, 0, src});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int stops = cur[1];
            int node = cur[2];

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto [next, price] : adj[node]) {
                if (cost + price < dist[next][stops + 1]) {
                    dist[next][stops + 1] = cost + price;
                    pq.push({cost + price, stops + 1, next});
                }
            }
        }

        return -1;
    }
};
