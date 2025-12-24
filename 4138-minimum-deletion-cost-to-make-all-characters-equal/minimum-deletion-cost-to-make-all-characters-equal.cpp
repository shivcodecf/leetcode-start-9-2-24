class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
    
     
     map<char,long long>mp;

     for(int i=0;i<s.size();i++)
     {
        mp[s[i]]+=cost[i];
     }

     long long total = 0;

     for(int i=0;i<cost.size();i++)
     {
       total+=cost[i];
     }

     long long mini = 1e18;

     for(auto it:mp)
     {
        mini = min(mini,total-it.second);
     }

     return mini;

    



        

    }
};