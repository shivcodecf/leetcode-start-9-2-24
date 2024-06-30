class Solution {
public:   
    
    int solve(int ind,int n, vector<int>& dp)
    {  

        

      if(ind>n)
      {
        return dp[n];
      }
      if(dp[ind]!=-1)
      {
        return dp[ind];
      }

      int x = solve(ind-1,n,dp) + solve(ind-2,n,dp);

     

      return dp[ind] = x;


     

    }

    int climbStairs(int n) {

        if(n<=1)
        {
            return n;
        }

         vector<int>dp(n+1,-1);

        dp[0]=1;
        dp[1]=1;

      

     

       return solve(n,n,dp); 

    }
};