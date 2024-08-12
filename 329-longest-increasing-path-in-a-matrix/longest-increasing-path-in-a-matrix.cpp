class Solution { 
   
        int solve(vector<vector<int>>& matrix,int n,int m, vector<vector<int>>& vis,int i,int j)
        {
            int drow[] = {-1,0,+1,0};

            int dcol[] = {0,+1,0,-1};

            if(i<0 || i>=n || j<0 || j>=m) return 0;

            if(vis[i][j]!=0) return vis[i][j];

          

            int check = matrix[i][j];

            int ans=1;

            for(int k=0;k<4;k++)
            {
               int nrow = i+ drow[k];
               int ncol = j+ dcol[k];

                if(nrow < 0 || ncol < 0 || nrow >= n || ncol >= m || check >= matrix[nrow][ncol])
                continue;

               if( matrix[nrow][ncol]>check)
               {
                   int res = 1+solve(matrix,n,m,vis,nrow,ncol);

                   ans=max(ans,res);
               }

             
            }

            return vis[i][j] = ans;

            
        }


public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));

        int maxi=-1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                
                    int len =  solve(matrix,n,m,vis, i, j);

                    maxi=max(maxi,len);
                
            }
        }

        return maxi;

        
       

    }
};