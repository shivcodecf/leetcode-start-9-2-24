class Solution {
public:  

//    static_cast<int>(c) 

    int solve(string& s1,string& s2,int n,int m,int i,int j,vector<vector<int>>& dp)
    { 

        if(i==n && j==m)
        {
            return 0;
        }

        if(i>=n){
            int sum=0;
            for(int indx=j;indx<s2.length();indx++){
                sum+=(int)s2[indx];
            }
            return sum;
        }
        if(j>=m){
            int sum=0;
            for(int indx=i;indx<s1.length();indx++){
                sum+=(int)s1[indx];
            }
            return sum;
        }

         if(dp[i][j]!=-1) return dp[i][j];
        


         if(s1[i]==s2[j])
         {
             return dp[i][j] = solve(s1,s2,n,m,i+1,j+1,dp);
         }
        //   delete 1 char
         int option1 = (int)s1[i]+solve(s1,s2,n,m,i+1,j,dp);

        //  delete 2 char

         int option2 = (int)s2[j]+solve(s1,s2,n,m,i,j+1,dp);

        //  delete both

        //  int option3 = solve(s1,s2,n,m,i+1,j+1)+static_cast<int>(s1[i])+static_cast<int>(s2[j]);

         return  dp[i][j] =  min(option2,option1);
        


    }

    int minimumDeleteSum(string s1, string s2) {
         vector<vector<int>> dp(1001,vector<int>(1001,-1));

       return solve(s1,s2,s1.size(),s2.size(),0,0,dp);

    }
};