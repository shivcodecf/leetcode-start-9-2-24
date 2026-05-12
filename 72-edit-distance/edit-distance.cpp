class Solution {
public:
    
    int solve(string& word1 , string& word2 , int i , int j,vector<vector<int>>& dp)
    {  
        int n = word1.size(),m=word2.size();

        if(i>=n || j>=m)
        {
            if(j>=m)
            {
                return n-i;
            }
            else {
               return m-j; 
            }
           
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int take1=INT_MAX,take2=INT_MAX;

        if(word1[i]==word2[j])
        {
            take1 = solve(word1,word2,i+1,j+1,dp);  
        }
        else {
           take2 = 1+min(solve(word1,word2,i,j+1,dp),min(solve(word1,word2,i+1,j,dp),solve(word1,word2,i+1,j+1,dp))); 
        }

        return dp[i][j] =  min(take1,take2);



    }


    int minDistance(string word1, string word2) {
       
       int n = word1.size(),m=word2.size();

       vector<vector<int>>dp(n,vector<int>(m,-1));
        
        
        return solve(word1,word2,0,0,dp);

    }
};