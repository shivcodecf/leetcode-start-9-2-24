class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> graph(n);

        // Build adjacency list
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        // Min heap: {cost, node, streak}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;

        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, streak] = pq.top();

            pq.pop();

            if (cost > dist[u][streak])
                continue;

            for (auto& [v, w] : graph[u]) {
                int newStreak;

                if (labels[u] == labels[v])
                    newStreak = streak + 1;
                else
                    newStreak = 1;

                if (newStreak > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newStreak]) {
                    dist[v][newStreak] = newCost;
                    pq.push({newCost, v, newStreak});
                }
            }
        }

        long long ans = INF;

        for (int streak = 1; streak <= k; streak++) {

            ans = min(ans, dist[n - 1][streak]);
        }

        return (ans == INF) ? -1 : ans;
    }
};