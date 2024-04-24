class Solution {
public:
    int numberOfSpecialChars(string word) {
          map<char,int>mp,mp1;

          vector<char>v,v1;
          int ans=0;
         

          for(int i=0;i<word.size();i++)
          { 
            

             if(islower(word[i]) )
             { 

               mp[word[i]]=i;

             }


          }
          int n=word.size();
          map<char,int>check;

          for(int i=0;i<n;i++)
          { 
              char ch=tolower(word[i]);

             if(isupper(word[i]) && check[ch] == 0)
             { 
               

                if(mp.find(ch)!=mp.end() && mp[ch]<i)
                {
                    ans++;
                   
                }
                 check[ch]++;
              

             }


          }



          

          return ans;

       






    }
};