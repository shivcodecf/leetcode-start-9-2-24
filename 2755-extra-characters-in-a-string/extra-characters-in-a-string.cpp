
 
class Solution {

    int solve(int ind,string& s, unordered_set<string>& st, vector<int>& dp)
    {
         if(ind>=s.size()) return 0;

         int res = INT_MAX;
          
         if(dp[ind]!=-1) return dp[ind];
         res = min(res,1+solve(ind+1,s,st,dp));

        for(int i=ind;i<s.size();i++)
        {
          string temp = s.substr(ind,i-ind+1);

          if(st.find(temp)!=st.end())
          {
             res = min(res,solve(i+1,s,st,dp));
          }

          
        }

        return  dp[ind] = res;

    }
public:
    int minExtraChar(string s, vector<string>& dict) {

        int n=s.size();

        vector<int>dp(n+1,-1);
    
    unordered_set<string>st(dict.begin(),dict.end());

    return solve(0,s,st,dp);
        

    }
};