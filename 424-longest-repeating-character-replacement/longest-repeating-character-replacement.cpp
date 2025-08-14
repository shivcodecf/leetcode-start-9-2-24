class Solution {
public:
    int characterReplacement(string s, int k) {
         
         map<char,int>mp;

         int ans =0,maxi = INT_MIN;

         int j=0;


         for(int i=0;i<s.size();i++)
         { 

            mp[s[i]]++;

            maxi = max(maxi,mp[s[i]]);

            while(i>j && ((i-j+1)-maxi)>k)
            {
                mp[s[j]]--;
                j++;
            }

            ans = max(ans,i-j+1);

         }

         return ans;

    }
};