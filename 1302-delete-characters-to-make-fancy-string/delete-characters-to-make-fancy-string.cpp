class Solution {
public:
    string makeFancyString(string s) {

        string ans="";
        int c=0,n=s.size();
        
      for(int i=0;i<s.size()-1;i++)
      { 

        if(s[i]==s[i+1])
        {
            c++;
            
           
        }

        else {
          if(c>=1)
          {
            ans+=s[i];
            ans+=s[i];
          }
          else {
            ans+=s[i];
          }
          c=0;
        }

      }

      if(c>=1)
      {
        ans+=s[n-2];
        ans+=s[n-2];
      }
      else {
        ans+=s[n-1];
      }

      return ans;


    }
};