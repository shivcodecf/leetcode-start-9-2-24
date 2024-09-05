class Solution {
public:
    string stringHash(string s, int k) {
        
        int n=s.size();
        int x=n/k;
        int sum1=0,sum2=0,check=0;

         string ans="";
         int j=0;
         map<int,char>mp;

         for(char ch = 'a' ;ch<='z';ch++)
         {
            mp[j++] = ch;
         }
        
        for(int i=0;i<n;i++)
        {   
             check++;

             sum1+=s[i]-'a';

             if(check==k)
             {  
                 int mod1 = sum1 % 26;
                 ans+=mp[mod1];
                 sum1=0;
                 check=0;
             }
             
        }

         return ans;

       

        






    }
};