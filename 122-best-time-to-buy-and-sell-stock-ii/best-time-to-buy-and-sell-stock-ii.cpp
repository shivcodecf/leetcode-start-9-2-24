class Solution {
public:
int n;

   int f(int index,vector<int>& prices,int values,int n,vector<vector<int>>& dp)
   {
       if(index==n)
       return 0;

       int profit=0;
       if(dp[index][values]!=-1) return dp[index][values];
       if(values)
       profit= max(-prices[index]+f(index+1,prices,0,n,dp),f(index+1,prices,1,n,dp));
       else 
       profit= max(prices[index]+f(index+1,prices,1,n,dp),f(index+1,prices,0,n,dp));
       return  dp[index][values]=profit;

       
   }
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       int res= f(0,prices,1,n,dp);
       return res;
        
    }
};