int dp[1001][1001];

class Solution {
private:
    int solve(string& text1,string& text2,int i,int j)
    {  

        if(i==text1.length() || j==text2.length()) return 0;

        int ans=0,ans1=0,ans2=0;

         if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]) 
        { 

            ans = 1+solve(text1,text2,i+1,j+1);


        }else
        { 

            ans1 = solve(text1,text2,i+1,j),

            ans2= solve(text1,text2,i,j+1);

        }

        return  dp[i][j] = max({ans,ans1,ans2});

    }

public:
    int longestPalindromeSubseq(string s) {
         memset(dp,-1,sizeof(dp));
         string revstr=s;
         reverse(revstr.begin(),revstr.end());
         return solve(s,revstr,0,0);

    }
};