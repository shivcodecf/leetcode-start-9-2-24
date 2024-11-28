class Solution {
public:
    int compress(vector<char>& chars) {

        string ans="";

        int c=0;

        if(chars.size()==1)
        
        {
            return 1;
        }
        
      for(int i=1;i<chars.size();i++)
      {  

        if(chars[i]==chars[i-1])
        {
          c++;
        }

        else {

            if(c>=1)
            {  
                ans+=chars[i-1];
                ans+=to_string(c+1);
               
            }
            else {
                ans+=chars[i-1];
            }

            c=0;
        }

      }

      if(c>=1)
      { 

        ans+=chars[chars.size()-1];

        ans+=to_string(c+1);


      }
      else {
        ans+=chars[chars.size()-1];
      }

      for(int i=0;i<ans.size();i++)
      {
        chars[i] = ans[i];
      }

      return ans.size();


    }
};