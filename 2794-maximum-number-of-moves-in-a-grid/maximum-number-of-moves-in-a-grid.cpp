set<pair<int,int>>st;
int dp[1000][1000];

class Solution {
     
     int solve(vector<vector<int>>& grid,int x,int y)
     { 
         int n=grid.size(),m=grid[0].size();

        //  if(st.count({x,y})) return 0;

         st.insert({x,y});

         int flag=0;

      
        int a=0,b=0,c=0;

        if(dp[x][y]!=-1) return dp[x][y];

        if(x-1>=0 && y+1<m && grid[x-1][y+1]>grid[x][y])
        {  
            flag=1;
            a = 1+ solve(grid,x-1,y+1);
        }
        if(y+1<m && grid[x][y+1]>grid[x][y])
        {  
            flag=1;
            b = 1+ solve(grid,x,y+1);
        }

        if(x+1<n && y+1<m &&  grid[x+1][y+1]>grid[x][y])
        {  
            flag=1;
            c = 1 + solve(grid,x+1,y+1);
        }

        if(flag==0)
        {
            return 0;
        }

        

        

        return dp[x][y] = max({a,b,c});



     }

public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));

        int res =0,ans=0;

        for(int i=0;i<n;i++)
        {
            res = solve(grid,i,0);
            ans = max(ans,res);
        }

        return ans;

    }
};