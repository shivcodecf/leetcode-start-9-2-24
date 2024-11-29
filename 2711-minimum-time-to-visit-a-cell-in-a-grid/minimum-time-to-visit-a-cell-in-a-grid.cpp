class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        set<pair<int,int>>st,st1;

        st.insert({0,0});

        

        while(!pq.empty())
        {
            auto it = pq.top();

            pq.pop();

            int flag=0;

            int x = it.first;

           

            int y = it.second.first;

            int z = it.second.second;


            if(y==n-1 && z==m-1)
            {
                return x;
            }
           if(y==0 && z==0)
           {
              if(grid[y][z+1]>1 && grid[y+1][z]>1)
            {
                return -1;
            }
           }
           

            

             if(y-1>=0 && st.find({y-1,z})==st.end())
            {   

                st.insert({y-1,z});

                if(grid[y-1][z]<=x+1)
                {
                   pq.push({x+1,{y-1,z}});
              
                    
                }
                else {
                    int diff = grid[y-1][z]-x;

                    int x = 0;

                    if(diff%2)
                    {
                        x = grid[y-1][z];
                    }
                    else {
                         x = grid[y-1][z]+1;
                    }

                    pq.push({x,{y-1,z}});

                    

                  
                }
               
            }

            if(y+1<n && st.find({y+1,z})==st.end())
            {      

                st.insert({y+1,z});

                if(grid[y+1][z]<=x+1)
                {
                   pq.push({x+1,{y+1,z}});
                  
                }
                else {
                    int diff = grid[y+1][z]-x;

                     int x = 0;

                    if(diff%2)
                    {
                        x = grid[y+1][z];
                    }
                    else {
                         x = grid[y+1][z]+1;
                    }

                    pq.push({x,{y+1,z}});

                    // pq.push({diff,{y+1,z}});
                }
               
               
            }

            if(z-1>=0 && st.find({y,z-1})==st.end() )
            {      

                st.insert({y,z-1});

                if(grid[y][z-1]<=x+1)
                {

                
                 pq.push({x+1,{y,z-1}});

                

                }
                else{

                     int diff = grid[y][z-1]-x;

                    int x = 0;

                    if(diff%2)
                    {
                        x = grid[y][z-1];
                    }
                    else {
                         x = grid[y][z-1]+1;
                    }

                    pq.push({x,{y,z-1}});

                }

               
            }

             if(z+1<m  && st.find({y,z+1})==st.end())
            {    

                st.insert({y,z+1});

                if(grid[y][z+1]<=x+1)
                {
                    pq.push({x+1,{y,z+1}});

                
                }
                else {
                       int diff = grid[y][z+1]-x;

                         int x = 0;

                    if(diff%2)
                    {
                        x = grid[y][z+1];
                    }
                    else {
                         x = grid[y][z+1]+1;
                    }

                    pq.push({x,{y,z+1}});
                }
               
                
            }

            

        }

        return -1;





    }
};