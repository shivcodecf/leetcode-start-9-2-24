class Solution {
public:
    bool scoreBalance(string s) {

        int sum =0;
        
        for(int i=0;i<s.size();i++)
        {
          sum+=s[i]-'a'+1;
        }

        int check = 0;


        for(int i=0;i<s.size();i++)
        {
          check+=s[i]-'a'+1;

          if(check*2==sum)
          {
            return true;
          }

        }

        return false;




        

    }
};