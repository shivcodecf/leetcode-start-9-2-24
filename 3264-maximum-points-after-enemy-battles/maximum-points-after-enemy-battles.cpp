class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int cenergy) {

        sort(enemyEnergies.begin(),enemyEnergies.end());
        reverse(enemyEnergies.begin(),enemyEnergies.end());
        long long x=-1,total=cenergy,n=enemyEnergies.size();
        for(int i=0;i<n;i++)
        {
           if(total>=enemyEnergies[i])
           {
            x=i;
            break;
           }
        }
        if(x==-1)
        {
            return 0;
        }

        for(int i=0;i<n-1;i++)
        {
            total+=enemyEnergies[i];
        }

        long long ans= total/enemyEnergies[n-1];

        return ans;



      
      

       return ans;








    }
};