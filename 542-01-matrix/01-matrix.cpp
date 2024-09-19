class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      
        int n = mat.size(),m = mat[0].size();

        queue<pair<int,pair<int,int>>>q;

         vector<vector<int>>v(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)

                {   
                     v[i][j] = 0;
                    q.push({0,{i,j}});
                }
            }
        }

       
        

        int drow [] ={-1,0,+1,0};

         int dcol [] ={0,+1,0,-1};


        while(!q.empty())
        {
             
             auto it = q.front();
           int x = it.first;

           int y = it.second.first;

           int z = it.second.second;

           q.pop();

           for(int k=0;k<4;k++)
           {  

            int nrow = drow[k] + y;

            int ncol = dcol[k] + z;

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && x+1 < v[nrow][ncol])
            {   

                v[nrow][ncol] = x+1;

                q.push({x+1,{nrow,ncol}});


            }





           }




        }

        return v;

       



    }
};