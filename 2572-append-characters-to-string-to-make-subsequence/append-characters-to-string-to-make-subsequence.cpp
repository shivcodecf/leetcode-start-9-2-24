class Solution {
public:
    int appendCharacters(string s, string t) {
        
       map<char,int>mp;

       for(int i=0;i<t.size();i++)
       {
        mp[t[i]]++;
       } 
       int j=0,c=0;

       for(int i=0;i<s.size();i++)
       { 
        
         if(s[i]==t[j])
         {
            j++;
            c++;
         }

       }
       return t.size()-c;

    }
};