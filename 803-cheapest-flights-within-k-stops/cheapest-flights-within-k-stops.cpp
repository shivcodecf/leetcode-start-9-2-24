class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& nums, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(auto it:nums)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        //{stops,{node,cost}}
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
            auto it= q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it:adj[node])
            {
                int adjNode=it[0];
                int edW=it[1];
                if(edW + cost < dist[adjNode] && stops<=k)
                {
                    dist[adjNode]=edW+cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};