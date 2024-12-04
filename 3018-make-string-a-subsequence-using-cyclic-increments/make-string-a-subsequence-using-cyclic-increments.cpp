class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int j=0,c=0;
        
       for(int i=0;i<str1.size();i++)
       {  

        char ch = str1[i];
        char ch1;

        if(ch=='z')
        {
            ch1 = 'a';
        }
        else {
            ch1 = ch+1;
        }


         
         if(ch==str2[j] || ch1==str2[j])
         {
          c++;
          j++;
         }

       }

       if(c>=str2.size())
       {
        return true;
       }

       return false;


    }
};