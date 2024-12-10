class Solution {
public:
    int maximumLength(string s) {
         
        map<string,int>mp;

        for(int i=0;i<s.size();i++)
        {   
             string s1 = "";

             map<char,int>mp1;

             
            for(int j=i;j<s.size();j++)
            {
               s1+=s[j];

               mp1[s[j]]++;

               if(mp1.size()==1)
               {
                  mp[s1]++;
               }
               else {
                break;
               }
              
            }


        }

        int ans=INT_MIN;


        for(auto it:mp)
        {
           if(it.second>=3)
           {
            ans = max(ans,(int)it.first.size());
           }
        }

        return ans==INT_MIN ? -1:ans;

        





    }
};