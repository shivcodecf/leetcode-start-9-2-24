class Solution {

    bool isValid(vector<vector<char>>& board, int i, int j, char d, int n,
                 int m) {
        int row = i;
        int col = j;

        for (int k = 0; k < n; k++) {
            if (board[k][col] == d) {
                return false;
            }
        }

        for (int k = 0; k < m; k++) {
            if (board[row][k] == d) {
                return false;
            }
        }

        row = i / 3 * 3;

        col = j / 3 * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[row + i][col + j] == d) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(int x, int y, vector<vector<char>>& board) {

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {

                    if (isValid(board, i, j, ch, n, m)) {

                        board[i][j] = ch;

                        if (solve(i, j, board)) {
                            return true;
                        }

                        board[i][j] = '.';
                    }
                }
                return false;
                }

                
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        int n = board.size(), m = board[0].size();

        solve(0, 0, board);
    }
};