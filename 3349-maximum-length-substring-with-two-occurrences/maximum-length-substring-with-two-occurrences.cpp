class Solution {
public:
    int maximumLengthSubstring(string s) { 

        int ans=0;
      
      for(int i=0;i<s.size();i++)
      {  
           map<char,int>mp;
          int sum=0;
         for(int j=i;j<s.size();j++)
        {
           mp[s[j]]++;
           if(mp[s[j]]<=2)
           {
            sum++;
           }
           else {
            break;
           }
        }
        ans=max(ans,sum);

      }
      return ans;
       

    }
};