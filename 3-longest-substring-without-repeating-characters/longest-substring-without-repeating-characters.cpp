class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char,int>mp;

        int j=0;

        int ans = 0;
        
        for(int i=0;i<s.size();i++)
        {

            mp[s[i]]++;

            if(mp[s[i]]==1)
            {  
                ans = max(ans,i-j+1);
                
            }

            else {

                while(i>j && mp[s[i]]>1)
                {
                   mp[s[j]]--;
                   j++;
                }

            }

            ans = max(ans,i-j+1);


   

        }

        return ans;

    }
};