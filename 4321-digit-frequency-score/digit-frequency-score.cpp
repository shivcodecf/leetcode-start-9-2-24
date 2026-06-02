class Solution {
public:
    int digitFrequencyScore(int n) {

        map<int,int>mp;

        while(n>0){
          int x = n%10;
          n = n/10;
          mp[x]++;  
        }

        int ans = 0;

        for(auto it:mp){
            ans+=it.first*it.second;
        }
        
        return ans;
    }
};