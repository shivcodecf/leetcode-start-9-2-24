class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        sort(spaces.begin(),spaces.end());

        string s1= "";

        int c=-1;

        int j=0;

        string ans="";

        int n=spaces.size();

        for(int i=0;i<s.size();i++)
        {
          
          if(j<n && i==spaces[j] )
          {
            ans+=' ';
            ans+=s[i];
            j++;
          }
          else {
             ans+=s[i];
          }

        }

        return ans;


    }
};