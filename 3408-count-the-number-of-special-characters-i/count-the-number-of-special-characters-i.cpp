class Solution {
public:
    int numberOfSpecialChars(string word) {
          map<char,int>mp,mp1;

          vector<char>v,v1;

        for(int i=0;i<word.size();i++)
        {

          if(islower(word[i])){

           char ch=tolower(word[i]);
           if(mp[ch]==0){
           mp[ch]++;
           }

          }


        }
        int ans=0;


        for(int i=0;i<word.size();i++)
        {  

            if(isupper(word[i]) && mp1[word[i]]==0)
            {
              
              char ch1=tolower(word[i]);
              if(mp[ch1]==1)
              {
                ans++;
              }
              mp1[word[i]]++;


            }
           
            
        }
        return ans;






    }
};