class Solution {
   int solve(string& text1 , string& text2,int x,int y,vector<vector<int>>& dp)
   {  

    if(x>=text1.size() || y>=text2.size())
    {
        return 0;
    }

    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }

    int take=0,skip1=0,skip2=0;
    if(text1[x]==text2[y])
    {
     take = 1+solve(text1,text2,x+1,y+1,dp);
    }
    else {

      skip1 = solve(text1,text2,x+1,y,dp);

      skip2 = solve(text1,text2,x,y+1,dp);  

    }

    return dp[x][y] =  max(take,max(skip1,skip2));

   }
  

public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size(),m=text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(text1,text2,0,0,dp);

    }
};