class Solution {
    private:

    int solve(string& s1,string& s2,int i,int j, vector<vector<int>>& dp)
    {  
        int n = s1.size(),m=s2.size();
        if(i==n || j==m)
        {
            if(i==n)
            {
                return abs(((m-1)-j)+1);
            }
            else {
                return abs(((n-1)-i)+1);
            }
        }

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int take1=INT_MAX,take2=INT_MAX,take3=INT_MAX;

        if(s1[i]==s2[j])
        {
           take1 = solve(s1,s2,i+1,j+1,dp);
        }

        else {

             take2 =  1+solve(s1,s2,i+1,j,dp);

             take3 =  1+solve(s1,s2,i,j+1,dp);

        }

        return dp[i][j]=min({take1,take2,take3});



    }

public:
    int minDistance(string word1, string word2) {
          int n = word1.size(),m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));

        return solve(word1,word2,0,0,dp);


    }
};