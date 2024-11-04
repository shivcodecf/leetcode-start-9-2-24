class Solution {
public:
    string compressedString(string word) {

        string ans = "";

        map<char,int>mp;

        int c = 0;

       for(int i=0;i<word.size()-1;i++)
       {
         
        if(word[i]==word[i+1] && c<8)
        { 

          c++;

        }
        else {
            c++;
            ans+=c+'0';
            ans+=word[i];
            c=0;  
        }

          
       }

       c++;

       ans+=c+'0';

       int n=word.size();

       ans+=word[n-1];


       return ans;





    }
};