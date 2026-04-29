class Solution {

    bool solve(string& s, vector<string>& wordDict,
               unordered_map<string, int>& mp, int ind,vector<int>& dp) {

        int n = s.size();

       if (ind == s.size()) return true;

       if(dp[ind]!=-1)
       {
        return dp[ind];
       }

        string s1 = "";

        for (int i = ind; i < s.size(); i++) {
            s1 += s[i];

            if (mp.find(s1) != mp.end()) {

                if(solve(s, wordDict, mp, i + 1,dp)){
                    return dp[ind] =  true;
                };
            }
        }

        return dp[ind] =  false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> mp;

        int n = s.size();

        vector<int>dp(n,-1);

        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]]++;
        }

        return solve(s, wordDict, mp, 0,dp);
    }
};