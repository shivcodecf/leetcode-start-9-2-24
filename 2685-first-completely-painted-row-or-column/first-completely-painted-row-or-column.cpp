class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         
         map<int,int>mp;

         for(int i=0;i<arr.size();i++)
         {
            mp[arr[i]] = i;
         }

         int n=mat.size(),m=mat[0].size();
         int ans=INT_MAX;

         for(int i=0;i<n;i++)
         {  
            int res = INT_MIN;

            for(int j=0;j<m;j++)
            {
             res = max(res,mp[mat[i][j]]);
            }

            ans = min(ans,res);

         }


         for(int i=0;i<m;i++)
         {  
            int res = INT_MIN;

            for(int j=0;j<n;j++)
            {
             res = max(res,mp[mat[j][i]]);
            }

            ans = min(ans,res);

         }

         return ans;


    }
};