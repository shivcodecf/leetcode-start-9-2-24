class Solution {
public:  
int ans=0;
int solve(string s,string t,int n,int m,int i,int j,  vector<vector<int>>& dp)
{

            if (j == m) return 1;
            // Base case: If i is the length of s but j is not the length of t, no match
            if (i == n) return 0;
            // If the result is already computed, return it
            if (dp[i][j] != -1) return dp[i][j];
            
            // Recursive case
            int take = 0, notTake = 0;
            if (s[i] == t[j]) {
                take = solve(s,t,n,m,i + 1, j + 1,dp);
            }
            notTake = solve(s,t,n,m,i + 1, j,dp);
            
            // Store the result in the DP table and return it
            return dp[i][j] = take + notTake;



 


}


    int numDistinct(string s, string t) {

      
      vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
    return solve( s,t,s.size(),t.size(),0,0,dp);

    


    }
};