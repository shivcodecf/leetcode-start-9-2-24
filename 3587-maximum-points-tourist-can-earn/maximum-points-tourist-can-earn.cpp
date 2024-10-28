int dp[2001][2001];

class Solution {
   
   int solve(vector<vector<int>>& stayScore,vector<vector<int>>& travelScore,int city,int day,int k,int n)
   {
     if(day==k) return 0;

     if(dp[city][day]!=-1) return dp[city][day];

     int res = stayScore[day][city]+solve(stayScore,travelScore,city,day+1,k,n);

     int temp=res;


     for(int j=0;j<n;j++)
     {   
        int res1=0;
        
        if(j!=city)
        {
            res1 =  travelScore[city][j]+solve(stayScore,travelScore,j,day+1,k,n);
            temp = max(temp,res1);
        }

       

        
     }

     return  dp[city][day] = temp;

   }

public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans = max(solve(stayScore,travelScore,i,0,k,n),ans);
        }
        return ans;

    }
};