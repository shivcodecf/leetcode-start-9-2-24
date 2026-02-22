class Solution {
    
    int solve(string& s1,string& s2,int i,int j,vector<vector<int>>& dp)
    {
        int n = s1.size(),m = s2.size();

        if(i>=n || j>=m)
        {
            return 0;
        }

        int take = 0,take1=0,take2=0;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s1[i]==s2[j])
        {
         take = 1+solve(s1,s2,i+1,j+1,dp);
        }
        else {
         take1 = solve(s1,s2,i+1,j,dp);
         take2 = solve(s1,s2,i,j+1,dp);
        }

        return dp[i][j] =  max({take,take1,take2});
    }

public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size(),m = text2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(text1,text2,0,0,dp);
        
    }
};