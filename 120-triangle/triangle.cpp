class Solution {
    int solve(vector<vector<int>>& triangle,int n,int x,int y,vector<vector<int>>& dp){

        if(x>=n){
          return 0;  
        }

        if(dp[x][y]!=INT_MAX)
        {
            return dp[x][y];
        }

        int left = INT_MAX , right = INT_MAX;

        left = triangle[x][y] + solve(triangle,n,x+1,y,dp);

        right = triangle[x][y] + solve(triangle,n,x+1,y+1,dp);

        return dp[x][y] =  min(left,right);

    } 
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        return solve(triangle,n,0,0,dp);
        
    }
};