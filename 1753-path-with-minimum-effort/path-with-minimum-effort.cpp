class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        

         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;


         pq.push({0,{0,0}});

         int n = heights.size();

         int m = heights[0].size();

         vector<vector<int>>dis(n+1,vector<int>(m+1,1e9));

         int dx[] = {0,+1,0,-1};

         int dy[] = {+1,0,-1,0};

       

        while(!pq.empty())
        {
            auto it = pq.top();

            pq.pop();

            int diff = it.first;

            int row = it.second.first;

            int col = it.second.second;

            if(row == n-1 && col == m-1)
            {
                return diff;
            }

            for(int i=0;i<4;i++)
            {
                int newR = row + dx[i];

                int newC = col + dy[i];

                

                if(newR>=0 && newC>=0 && newR<n && newC<m && dis[newR][newC]>max(diff,abs(heights[row][col]-heights[newR][newC])))
                {  
                   int newDiff = max(diff,abs(heights[row][col]-heights[newR][newC]));

                   dis[newR][newC] = newDiff;

                   pq.push({newDiff,{newR,newC}});
                }

            }


        }

        return -1;



    }
};