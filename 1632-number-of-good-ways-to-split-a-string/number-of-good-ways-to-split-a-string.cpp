class Solution {
public:
    int numSplits(string s) {
        
        map<char,int>mp,mp1;


        for(int i=0;i<s.size();i++)
        {
             mp[s[i]]++;
        }

        int x= mp.size(),cnt=0,ans=0;

        for(int i=0;i<s.size();i++)
        {  

            mp[s[i]]--;

            mp1[s[i]]++;

            if(mp[s[i]]==0)
            {
                
                cnt++;

                mp.erase(s[i]);

            }

            int left = x-cnt;

            if(left == mp1.size())
            {
                ans++;
            }

            
            
        }

        return ans;



    }
};