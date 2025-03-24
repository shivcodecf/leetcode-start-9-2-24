class Solution {
public:
    int characterReplacement(string s, int k) {
         

         int j=0;

         map<char,int>mp;

         int check = INT_MIN,ans = 0;

        for(int i=0;i<s.size();i++)
        {   
              mp[s[i]]++;

             check = max(check,mp[s[i]]);

             while(j<s.size() && (i-j+1)-check>k)
             { 

              mp[s[j]]--;
              
              j++;

             }

             ans = max(ans,i-j+1);


        } 

        return ans;
    }
};