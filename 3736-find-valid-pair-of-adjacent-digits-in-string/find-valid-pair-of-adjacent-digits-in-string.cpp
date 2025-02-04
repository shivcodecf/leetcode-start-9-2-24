class Solution {
public:
    string findValidPair(string s) {

        map<int,int>mp;
        
        for(int i=0;i<s.size();i++)
        {
          mp[s[i]-'0']++;
        }

        for(int i=1;i<s.size();i++)
        {
            if(mp[s[i]-'0'] == s[i]-'0' && mp[s[i-1]-'0'] == s[i-1]-'0' && s[i-1]-'0'!=s[i]-'0')
            {  
                string ans = "";
               ans+=s[i-1];
               ans+=s[i];

               return ans;
            }
        }
        return "";
    }
};