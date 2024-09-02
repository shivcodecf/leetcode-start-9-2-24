class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e9); // Initialize distances to a large value

        // Adjacency list for the graph
        map<int, vector<pair<int, int>>> mp;

        // Build the graph from the flights data
        for(int i = 0; i < flights.size(); i++) {
            mp[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // Priority queue: {stops, {current city, cost to reach that city}}
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;

        // Start from the source city with 0 cost and 0 stops
        pq.push({0, {src, 0}});
        dis[src] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int city = it.second.first;
            int cost = it.second.second;

            // If we've made more than k stops, skip this path
            if (stops > k) continue;

            // Explore the neighbors of the current city
            for(auto neighbor : mp[city]) {    
                int nextCity = neighbor.first;
                int flightCost = neighbor.second;
                int newCost = cost + flightCost;

                // If the new cost is less than the known distance, update and push to the queue
                if (newCost < dis[nextCity]) {
                    dis[nextCity] = newCost;
                    pq.push({stops + 1, {nextCity, newCost}});
                }
            }
        }

        // If the destination is unreachable, return -1
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};
