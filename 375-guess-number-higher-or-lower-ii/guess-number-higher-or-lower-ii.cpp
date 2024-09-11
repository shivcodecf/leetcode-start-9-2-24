int dp[2001][2001];

class Solution {

    int solve(int start,int end)
    {  

        if( start>= end)  return 0;
        if(dp[start][end]!=-1) return dp[start][end];

        int maxi = INT_MAX;

        for(int i=start;i<=end;i++ )
        { 
           

            maxi = min(maxi, i + max(solve(start,i-1),solve(i+1,end)));


        }



        return dp[start][end] = maxi;


    }
public:
    int getMoneyAmount(int n) {
        
        memset(dp,-1,sizeof(dp));

       return solve(1,n);
     

    }
};