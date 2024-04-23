class Solution {
public:
    int numberOfSpecialChars(string word) {
          map<char,int>mp,mp1;

          vector<char>v,v1;
          int ans=0;

          for(int i=0;i<word.size();i++)
          {
            for(int j=i+1;j<word.size();j++)
            {
                int x= abs(word[i]-word[j]);
                 char ch=tolower(word[i]);
                if(x==32 && mp[ch]==0)
                {
                    ans++;
                   

                    mp[ch]++;
                    
                }
            }
          }

          return ans;

       






    }
};