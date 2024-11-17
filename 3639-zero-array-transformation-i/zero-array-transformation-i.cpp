class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

       int n=nums.size();
       int m=queries.size();

       vector<int>pref(n);

       for(int i=0;i<m;i++)
       { 

        int x = queries[i][0];

        int y= queries[i][1];

        pref[x]+=1;
         
         if(y+1<n)
         {
            pref[y+1]-=1;
         }

        

       }

       int cnt=0;

       for(int i=0;i<n;i++)
       {

        cnt+=pref[i];

        if(cnt<nums[i])
        {
            return false;
        }

       }

       return true;


    }
};