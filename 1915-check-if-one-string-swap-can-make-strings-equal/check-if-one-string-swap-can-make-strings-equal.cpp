class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

      

        

        if(s1.size()!=s2.size())
        {
            return false;
        }

        map<char,int>mp;

        

        int c=0;
        
        for(int i=0;i<s1.size();i++)
        {
          if(s1[i]!=s2[i])
          {
            c++;
          }
        }

          sort(s1.begin(),s1.end());
          sort(s2.begin(),s2.end());

          for(int i=0;i<s1.size();i++)
          {
            if(s1[i]!=s2[i])
            {
                return false;
            }
          }


        return c<=2 ? true : false;

    }
};