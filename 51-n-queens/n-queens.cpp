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
        for (int i = row1 - 1, j = col1 - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Check anti-diagonal (upper right diagonal)
        for (int i = row1 - 1, j = col1 + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, n, row, col)) {
                board[row][col] = 'Q';
                solve(n, row + 1, board, solutions);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solve(n, 0, board, solutions);
        return solutions;
    }
};
