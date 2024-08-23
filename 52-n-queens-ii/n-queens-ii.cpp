class Solution { 
  
    private:
    bool isValid(vector<string>& board, int n, int row1, int col1) {
        // Check column
        for (int i = 0; i < row1; i++) {
            if (board[i][col1] == 'Q') {
                return false;
            }
        }
        // Check main diagonal (upper left diagonal)
        int x=row1,y=col1;
        while (x<n && y<n && x>=0 && y>=0) {
            if (board[x][y] == 'Q') {
                return false;
            }

            x--;
            y++;
        }
        // Check anti-diagonal (upper right diagonal)
        x= row1,y=col1;
        while (x>=0 && y>=0 && x<n && y<n) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        
        return true;
    }

    void solve(int n, int row, vector<string>& board, int& ans) {
        if (row == n) {

            ans++;
            return;

           
            
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, n, row, col)) {
                board[row][col] = 'Q';
                solve(n, row + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        
        int ans=0;

        vector<string> board(n, string(n, '.'));
        solve(n, 0, board, ans);
        return ans;


    }
};