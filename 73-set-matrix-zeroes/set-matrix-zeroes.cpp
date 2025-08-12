class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<pair<int,int>>v;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back({i,j});
                }
            }
        }

        int n = matrix.size();

        int m= matrix[0].size();

        for(int i=0;i<v.size();i++)
        {
            int x = v[i].first;
            int y = v[i].second;

            for(int j=0;j<m;j++)
            {
                matrix[x][j] = 0;
            }

             for(int k=0;k<n;k++)
            {
                matrix[k][y] = 0;
            }
        }

        // return matrix;
        
    }
};