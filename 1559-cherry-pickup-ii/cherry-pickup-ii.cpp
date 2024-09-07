class Solution { 

    int dp[70][70][70];
  
  int solve(vector<vector<int>>& grid,int x1,int y1,int y2)
  {   

          int n=grid.size();
          int m=grid[0].size();

          if( y1<0  || y1>=m ||  y2<0  || y2>=m || x1>=n) return 0;

          if(dp[x1][y1][y2]!=-1) return dp[x1][y1][y2];

        //   if(x1==n-1){

        //     if( y1==y2)
        //     {
        //         return grid[x1][y1];
        //     }

        //     return grid[x1][y1] + grid[x1][y2];

        //   } 
         
          int ans = 0;
 
         

         if(y1==y2 )
         {
           ans=grid[x1][y1];
         }
         else {
            ans = grid[x1][y1] + grid[x1][y2];
         }
           
           
          int t1 = solve(grid,x1+1,y1-1,y2-1);

          int t2 = solve(grid,x1+1,y1-1,y2);

          int t3 = solve(grid,x1+1,y1-1,y2+1);//

          int t4 = solve(grid,x1+1,y1,y2-1);//

          int t5 = solve(grid,x1+1,y1,y2);//

          int t6 = solve(grid,x1+1,y1,y2+1);

          int t7 = solve(grid,x1+1,y1+1,y2-1);

          int t8 = solve(grid,x1+1,y1+1,y2);

          int t9 = solve(grid,x1+1,y1+1,y2+1);

          ans+= max({t1,t2,t3,t4,t5,t6,t7,t8,t9});

          return dp[x1][y1][y2]  = ans;


        
  }

public:
    int cherryPickup(vector<vector<int>>& grid) {
         
         int n=grid.size();

         int m=grid[0].size();

         memset(dp,-1,sizeof(dp));

         return solve(grid,0,0,m-1);

    }
};