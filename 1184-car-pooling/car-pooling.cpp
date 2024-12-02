class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();

        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int x = trips[i][0];

            int y = trips[i][1];

            int z = trips[i][2];

            mp[y]+=x;

            

            mp[z]-=x;

           


        }



        int sum=0;

        for(int i=0;i<=1000;i++)
        {    
            sum+=mp[i];
            cout <<mp[i]<<" ";

            if(sum>capacity)
            {
                return false;
            }
        }

        return true;





    }
};