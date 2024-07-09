class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n=customers.size(),ans=0,x=0,start=0,diff=0;
        
        for(int i=0;i<n;i++)
        {
             diff = max((double)customers[i][0],(double)start)+customers[i][1];
             ans+= diff-customers[i][0];
             start=diff;
            
        }

        double res = (double)(ans/n);


        return res;

    }
};