class Solution {

    bool isValid(vector<vector<char>>& board, int x, int y, int d) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == d) {
                return false;
            }
            if (board[i][y] == d) {
                return false;
            }
        }

        int startI = x / 3 * 3;

        int startJ = y / 3 * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startI + i][startJ + j] == d) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        int n = board.size(), m = board[0].size();

        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                if (board[k][l] != '.')
                    continue;

                for (int d = '1'; d <= '9'; d++) {
                    if (isValid(board, k, l, d)) {
                        board[k][l] = d;
                        if(solve(board, k, l)){
                            return true;
                        }
                        board[k][l] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};