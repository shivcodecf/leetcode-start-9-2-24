class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
         
         int n=grid.size(),m=grid[0].size();

         vector<vector<int>>v(n,vector<int>(m));

         int mid;


         if(k%2)
         {
           mid = k/2;
         }
         else {
            mid = k/2-1;
         }

         int row = x+k-1;


         for(int i=x;i<n;i++)
         {  
           
           mid--;

           for(int j=y;j<y+k;j++)
           {

             swap(grid[i][j] , grid[row][j]);

              cout <<grid[i][j]<<" ";


           } 

           row  = row-1;

           cout <<endl;

           if(mid<0)
           {
            break;
           }

        
         }

         return grid;

         

         


    }
};