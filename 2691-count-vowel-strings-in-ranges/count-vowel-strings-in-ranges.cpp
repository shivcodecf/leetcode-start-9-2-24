class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n=words.size();

        vector<int>pref(n);

        map<char,int>mp;

        mp['a']++;

        mp['e']++;

        mp['i']++;

        mp['o']++;

        mp['u']++;

        int sum=0;

        for(int i=0;i<n;i++)
        { 

            int x = words[i].size();
         char ch = words[i][0];

         char ch1 = words[i][x-1];

         if(mp[ch]>0 && mp[ch1]>0)
         {
           sum++;
         }
         pref[i] = sum;

        }

        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {  
          int a = queries[i][0];

          int b = queries[i][1];

          if(a==0)
          {
             ans.push_back(pref[b]);
          }

          else {
            ans.push_back(pref[b]-pref[a-1]);
          }


        }

         return ans;

    }
};