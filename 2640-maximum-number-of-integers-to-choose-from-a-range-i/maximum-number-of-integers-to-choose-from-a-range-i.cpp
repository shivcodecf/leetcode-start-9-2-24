class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int sum=0,c=0;

        map<int,int>mp;


        for(int i=0;i<banned.size();i++)
        {
            mp[banned[i]]++;
        }
        
        for(int i=1;i<=n;i++)
        { 
         if(sum+i<=maxSum && mp.find(i)==mp.end())
         {
            sum+=i;
            c++;
         }
         
        }

        return c;



    }
};