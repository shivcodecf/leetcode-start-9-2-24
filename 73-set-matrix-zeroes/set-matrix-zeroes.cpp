class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();

         vector<int>v,v1;

       


       for(int i=0;i<n;i++)
       { 

        for(int j=0;j<m;j++)
        {
           if(matrix[i][j]==0)
           {
             v.push_back(i);
             v1.push_back(j);
           }
        }

       }

       for(int i=0;i<v.size();i++)
       {
          for(int j=0;j<m;j++)
          {
            matrix[v[i]][j] = 0;
          }
       } 

        for(int i=0;i<v1.size();i++)
       {
          for(int j=0;j<n;j++)
          {
            matrix[j][v1[i]] = 0;
          }
       } 





    }
};