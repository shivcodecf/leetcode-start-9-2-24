class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n=grid.size(),m=grid[0].size();

        map<vector<int>,int>mp;
        vector<int>v;

        for(int i=0;i<n;i++)
        {   
             vector<int>v;

            for(int j=0;j<m;j++)
            {
                v.push_back(grid[i][j]);
            }
            mp[v]++;
            
        } 

          int ans=0;
         for(int i=0;i<m;i++)
        {   
             vector<int>v;

            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
           if(mp.find(v)!=mp.end())
           {
              
              ans+=mp[v];
           }
            
        }
        return ans;



    }
};