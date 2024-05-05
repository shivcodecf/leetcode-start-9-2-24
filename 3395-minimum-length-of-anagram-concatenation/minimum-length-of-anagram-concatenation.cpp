class Solution {
public:
    int minAnagramLength(string s) {
       
       
       map<char,int>mp;

      for(int i=0;i<s.size();i++)
      {
        mp[s[i]]++;
      }
     
      vector<int>v;

      for(auto i:mp)
      {
      
        v.push_back(i.second);
        
      }
      sort(v.begin(),v.end());
      int ans=0,check=v[0];

      for(int i=1;i<v.size();i++)
      {

        check=__gcd(check,v[i]);

      }
     
      for(int i=0;i<v.size();i++)
      {

        ans+= v[i]/check;

      }

      return ans;

     



    }
};