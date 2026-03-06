class Solution {
    
    int solve(string& word1,string& word2,int i,int j, vector<vector<int>>& dp)
    {

     int n = word1.size(),m=word2.size();   
  
     if(i>=n || j>=m)
     {
        if(i<=n-1)
        {
            return n-1-i+1;
        }
         if(j<=m-1)
        {
            return m-1-j+1;
        }

        return 0;
     }

     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }
     
     int equal = INT_MAX , del1=INT_MAX, del2= INT_MAX;
     if(word1[i]==word2[j])
     {
      equal = solve(word1,word2,i+1,j+1,dp);
     }
     else {
       del1 = 1+solve(word1,word2,i,j+1,dp);
       del2 = 1+solve(word1,word2,i+1,j,dp);
     }

     return dp[i][j] = min({equal,del1,del2});

    }

public:
    int minDistance(string word1, string word2) {

         int n = word1.size(),m=word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(word1,word2,0,0,dp);
        
    }
};