class Solution {
        
        int solve(string& s1, string& s2, int i ,int j,vector<vector<int>>& dp)
        {

            if(s1.size()<=i  ||  j>=s2.size())
            {
                return 0;
            }

            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }

            int take = INT_MIN , notake = INT_MIN;

            if(s1[i]==s2[j])
            {
                take = 1+solve(s1,s2,i+1,j+1,dp);
            }

            else {

                notake = max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));

            }

             return dp[i][j] =  max(take,notake);

        }


public:
    int longestPalindromeSubseq(string s) {

        string s1 = s;

        string s2 = s1;

        reverse(s2.begin(),s2.end());

        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));


        return solve(s1,s2,0,0,dp);
        
    }
};