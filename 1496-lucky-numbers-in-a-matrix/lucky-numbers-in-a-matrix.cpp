class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        
        int n= matrix.size(),m= matrix[0].size(),mini=INT_MAX;

        vector<int>ans;

        for(int i=0;i<n;i++)
        {   
            mini=INT_MAX;int ind=0;

            for(int j=0;j<m;j++)
            {
                if(mini>matrix[i][j])
                {
                    ind = j;
                    mini=matrix[i][j];
                }
            }

            int maxi=INT_MIN;

            for(int k=0;k<n;k++)
            {
               maxi = max(maxi,matrix[k][ind]);
            }

            if(maxi==mini)
            {
                ans.push_back(maxi);
            }






        }

        return ans;






    }
};