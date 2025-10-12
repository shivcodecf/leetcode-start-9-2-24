class Solution {

         bool check( unordered_map<char, int>& mp)
         {  
            int maxi = 0;

            int mini = INT_MAX;

            for(auto it:mp)
            {
                maxi = max(maxi,it.second);

                mini = min(mini,it.second);
            }

            return maxi==mini;


         }


public:
    int longestBalanced(string s) {

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            unordered_map<char, int> mp;

            for (int j = i; j < s.size(); j++) {

                mp[s[j]]++;

               

                int x = 0,y=INT_MAX;

                for(auto it:mp)
                {
                    x = max(x,it.second);

                    y = min(y,it.second);
                }

                if(x==y)
                {
                    ans = max(ans,j-i+1);
                }

            }


        }


        return ans;




    }
};