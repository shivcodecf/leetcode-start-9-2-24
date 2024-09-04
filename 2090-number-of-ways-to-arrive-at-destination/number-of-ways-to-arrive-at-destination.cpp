class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

         using ll = long long;
    const ll MOD = 1e9 + 7;
    
    // Adjacency list to store the graph
    vector<vector<pair<ll, ll>>> adj(n);
    
    for (auto& road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }
    
    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    // Distance vector and paths count vector
    vector<ll> dist(n, LLONG_MAX);
    vector<ll> ways(n, 0);
    
    // Start from node 0
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        ll d = it.first;
        ll node = it.second;
        
        if (d > dist[node]) continue;
        
        for (auto& neighbor_pair : adj[node]) {
            ll neighbor = neighbor_pair.first;
            ll weight = neighbor_pair.second;
            
            ll newDist = d + weight;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
                ways[neighbor] = ways[node];
            } else if (newDist == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
            }
        }
    }
    
    return ways[n - 1]; 

    }
};