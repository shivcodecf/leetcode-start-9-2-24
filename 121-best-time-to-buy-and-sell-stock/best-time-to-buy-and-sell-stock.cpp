class Solution {
public:
    int f(int ind,vector<int>& prices,int value,int n, vector<vector<int>>& dp){
    if(ind ==n)
    return 0;
    int profit=0;
    if(dp[ind][value]!=-1)  return dp[ind][value];
    if(value)
    {
         profit=max(-prices[ind]+f(ind+1,prices,0,n,dp),f(ind+1,prices,1,n,dp));

    }
    else {
        profit=max(prices[ind],f(ind+1,prices,0,n,dp));
    }
    return dp[ind][value]=profit;
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return f( 0,prices,1, n,dp);
    }
};