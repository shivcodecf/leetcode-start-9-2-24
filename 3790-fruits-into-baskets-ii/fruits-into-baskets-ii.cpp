class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int ans=0,ind=-1;

        map<int,int>mp;

        int n=fruits.size();
        
     for(int i=0;i<fruits.size();i++)
     {
        for(int j=0;j<baskets.size();j++)
        {
          if(baskets[j]>=fruits[i] && mp[j]==0)
          {
            
            ans++;
            mp[j]++;
            break;
          }
        }
     }

     return n-ans; 


    }
};