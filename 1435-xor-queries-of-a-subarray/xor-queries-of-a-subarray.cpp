class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size(),m=queries.size();

        vector<int>ans;
         
         for(int i=0;i<m;i++)
         {
            int x=queries[i][0];

            int y=queries[i][1];
            int xr=0;

            for(int j=x;j<=y;j++)
            {
               xr = xr ^ arr[j];
            }

            ans.push_back(xr);
         }

         return ans;

    }
};