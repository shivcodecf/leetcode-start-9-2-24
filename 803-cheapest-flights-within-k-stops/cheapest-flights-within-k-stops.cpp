class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dis(n,1e9);

        map<int,vector<pair<int,int>>>mp;

        for(int i=0;i<flights.size();i++)
        {
           mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue<
        pair<int, pair<int, int>>,            // Type of elements in the priority queue
        vector<pair<int, pair<int, int>>>, // Underlying container (vector)
        greater<pair<int, pair<int, int>>>  // Comparison function (greater for min-heap)
    > pq;

    pq.push({0,{src,0}});

    dis[src] = 0;

    

    while(!pq.empty())
    {
        auto it = pq.top();

        pq.pop();

        int x = it.first;

        int y = it.second.first;

        int z = it.second.second;

        if(x>k) continue;

        for(auto it1:mp[y])
        {    
              int val  = it1.first;
              int cost = it1.second;

              int sum = z + cost;

              if(sum<dis[val] )
              {
                 dis[val] = sum;
                 pq.push({x+1,{val,sum}});
              }
        }

    }


    if(dis[dst]==1e9) return -1;

    return  dis[dst];



    }
};  