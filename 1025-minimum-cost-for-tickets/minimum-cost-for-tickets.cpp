class Solution {
public:  
        
        int solve(vector<int>& days,vector<int>& cost,int n,int ind, vector<int>& dp)
        {
            if(ind>=n)
            {
                return 0;
            }

            if(dp[ind]!=-1)
            {
                return dp[ind];
            }
            // cost0
            
            int option1 = cost[0] + solve(days,cost,n,ind+1,dp);

           

           int i;

            // cost[1]
             for( i=ind; i<n && days[i]<days[ind]+7; i++);

            int option2 = cost[1]+solve(days,cost,n,i,dp);

            // cost[2]

             for( i=ind; i<n && days[i]<days[ind]+30; i++);


             int option3 = cost[2]+solve(days,cost,n,i,dp);


             return dp[ind]=min({option1,option2,option3});

        }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

         int n=days.size();

         vector<int>dp(n+1,-1);

        return solve(days,costs,n,0,dp);



    }
};