class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        int p2=0,p3=0,p5=0;
        dp[0]=1;
        for(int i=1;i<n;i++)
        { 
            int x= 2*dp[p2];
            int y= 3*dp[p3];
            int z= 5*dp[p5];
           dp[i]=min(x,min(y,z));

           if(dp[i]==x) p2++;
           if(dp[i]==y) p3++;
           if(dp[i]==z) p5++;

        }
        return dp[n-1];
    }
};