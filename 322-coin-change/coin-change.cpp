class Solution {

   long long solve(vector<int>& coins,int target,int index,int sum,vector<vector<int>>& dp)
   {

    int n = coins.size();

    if(sum<0)
    {
        return INT_MAX;
    }

    if(sum == 0)
    {
        return 0;
    }

    if(index>=n)
    {
     if(sum == 0)
     {
        return 0;
     }
     return INT_MAX;
    }

    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }

    long long take = 1+solve(coins,target,index,sum-coins[index],dp); 

    long long take1 = 1+solve(coins,target,index+1,sum-coins[index],dp); 

    long long notake = solve(coins,target,index+1,sum,dp); 

    return dp[index][sum] =  min({take,take1,notake});



   }

public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(),coins.end());

        // reverse(coins.begin(),coins.end());

        int n = coins.size();

         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        long long ans = solve(coins,amount,0,amount,dp);

        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
        
    }
};