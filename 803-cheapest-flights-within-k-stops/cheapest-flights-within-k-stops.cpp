class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights) {

            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;

        // stops, {node, cost}
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        while(!q.empty()) {

            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            if(stops > k) continue;

            for(auto &neigh : adj[node]) {

                int adjNode = neigh.first;
                int wt = neigh.second;

                if(cost + wt < dist[adjNode]) {

                    dist[adjNode] = cost + wt;

                    q.push({
                        stops + 1,
                        {adjNode, cost + wt}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};