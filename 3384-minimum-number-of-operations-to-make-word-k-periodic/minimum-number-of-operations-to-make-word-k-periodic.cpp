class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
      
      map<string,int>mp;
      int check=0;

      for(int i=0;i<word.size()-k+1;i++)
      { 

        if(i%k==0)
        {
            string s1=word.substr(i,k);
            mp[s1]++;
            check++;
        }
       
       
      }
      int maxi=0;
      for(auto i:mp)
      {
        maxi=max(maxi,i.second);
      }

      return check-maxi;



    }
};