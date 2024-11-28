class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
       std::priority_queue<std::pair<int, std::pair<int, int>>, 
                        std::vector<std::pair<int, std::pair<int, int>>>, 
                        std::greater<std::pair<int, std::pair<int, int>>>> pq;

           set<pair<int,int>>st;

           pq.push({0,{0,0}});
           st.insert({0,0});

           int ans=0;

           int n=grid.size();

           int m= grid[0].size();

      

        while(!pq.empty())
        {    

           

            auto it = pq.top();

            pq.pop();

            int x = it.first;

            int y = it.second.first;

            int z = it.second.second;

            if(y==n-1 && z==m-1)
            {
                return x;
            }

            if(y-1>=0 && st.find({y-1,z})==st.end())
            {  
               if(grid[y-1][z]==1)
               {
                 pq.push({x+1,{y-1,z}});
               }
               else {
                pq.push({x,{y-1,z}});
               }
               st.insert({y-1,z});
              
            }

            if(y+1<n && st.find({y+1,z})==st.end() )

            {
                if(grid[y+1][z]==1)
               {
                 pq.push({x+1,{y+1,z}});
               }
               else {
                pq.push({x,{y+1,z}});
               }

               st.insert({y+1,z});
            }

            if(z-1>=0 && st.find({y,z-1})==st.end())
            {
                if(grid[y][z-1]==1)
               {
                 pq.push({x+1,{y,z-1}});
               }
               else {
                pq.push({x,{y,z-1}});
               }
               st.insert({y,z-1});
            }

            
            if(z+1<m &&  st.find({y,z+1})==st.end())
            {
                if(grid[y][z+1]==1)
               {
                 pq.push({x+1,{y,z+1}});
               }
               else {
                pq.push({x,{y,z+1}});
               }

                st.insert({y,z+1});
            }



        }

        return -1;



       



    }
};