class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        // u -> {v, wt}
        for(auto &it : times) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        dist[k] = 0;

        while(!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto neigh : adj[node]) {

                int adjNode = neigh.first;
                int wt = neigh.second;

                if(dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = INT_MIN;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};