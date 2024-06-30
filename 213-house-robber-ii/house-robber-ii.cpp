class Solution {
public:  
     int solve(vector<int>& A,int n,int ind,int sum,vector<int>& dp)
{
    if(ind==n)
    {
        return A[ind];
    }
    if(ind>n)
    {
        return 0;
    }
    
   
   
   if(dp[ind]!=-1)
   {
       return dp[ind];
   }

     int take=0,notake= 0;

    take = solve(A,n,ind+2,sum,dp)+A[ind];
  
    notake = solve(A,n,ind+1,sum,dp);
   

    return dp[ind]=max(take,notake);

}

    int rob(vector<int>& A) {

     int n=A.size();
     vector<int>dp(n+1,-1);
      vector<int>dp1(n+1,-1);
    
     if(n==2)
     {
         return max(A[0],A[1]);
     }
     if(n==1)
     {
        return A[0];
     }

      return max(solve(A,n-2,0,0,dp),solve(A,n-1,1,0,dp1));

      
    }
};