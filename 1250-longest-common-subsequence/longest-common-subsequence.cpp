
int dp[1001][1001];
class Solution {
   private:
    int solve(string& s1,string& s2,int i,int j)
    { 

        int n=s1.size(),m=s2.size();
     
        if(i>=n || j>=m) return 0;
      
        int take = INT_MIN,take1 =INT_MIN,take2=INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j])
        {
            take = 1 +  solve(s1,s2,i+1,j+1);
        }
        else {
            take1 = solve(s1,s2,i+1,j);

            take2 = solve(s1,s2,i,j+1);
        }

        return  dp[i][j] = max({take,take1,take2});




     



        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        memset(dp,-1,sizeof(dp));
        
        return solve(text1,text2,0,0);

    }
};