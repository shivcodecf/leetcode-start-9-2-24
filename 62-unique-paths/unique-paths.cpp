class Solution {
   
   private:

   int solve(int i,int j,int m,int n, vector<vector<int>>& dp)
   { 
    if(i>=m || j>=n || i<0 || j<0)
    {
        return 0;
    }
    if(i==m-1 && j==n-1)
    {
        return 1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

     int down = solve(i+1,j,m,n,dp);
     int right = solve(i,j+1,m,n,dp);

     return dp[i][j] = down + right ;

   }

public:
    int uniquePaths(int m, int n) {

        
        vector<vector<int>>dp(m,vector<int>(n,-1));

       return  solve(0,0,m,n,dp); 

    }

};