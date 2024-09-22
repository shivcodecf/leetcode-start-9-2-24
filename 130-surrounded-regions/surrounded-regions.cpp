class Solution {

    private:

    void dfs(vector<vector<char>>& board,int x,int y)

    {
          int n=board.size(),m=board[0].size();

          board[x][y] = '1';

          int drow[] = {-1,0,+1,0};

          int dcol[] = {0,+1,0,-1};

          for(int k=0;k<4;k++)
          { 

             int nrow = x+drow[k];

             int ncol = y+dcol[k];
             
             if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && board[nrow][ncol]=='O')
             {
                dfs(board,nrow,ncol);
             }




          }




    }


public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size(),m=board[0].size();

         
         for(int i=0;i<m;i++)
         { 

            if(board[0][i]=='O')
            {
               dfs(board,0,i);
            }

            if(board[n-1][i]=='O')
            {
               dfs(board,n-1,i);
            }

         }

          for(int i=0;i<n;i++)
         { 

            if(board[i][0]=='O')
            {
               dfs(board,i,0);
            }

            if(board[i][m-1]=='O')
            {
               dfs(board,i,m-1);
            }

         }

         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='1')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
         }

      


         
      



    }
};