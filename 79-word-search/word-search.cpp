class Solution {

    bool solve(vector<vector<char>>& board, string& word, int n, int m, int i,
               int j, vector<vector<char>>& vis, int ind) {

        int l = word.size();

        if (ind >= l) {
            return true;
        }

        if (j + 1 < m && word[ind] == board[i][j + 1] &&
            vis[i][j + 1] == '.') {

            vis[i][j + 1] = board[i][j + 1];

            if (solve(board, word, n, m, i, j + 1, vis, ind + 1)) {
                return true;
            }

            vis[i][j + 1] = '.';

        }

        if (i - 1 >= 0 && word[ind] == board[i - 1][j] &&
            vis[i - 1][j] == '.') {

            vis[i - 1][j] = board[i - 1][j];

            if (solve(board, word, n, m, i - 1, j, vis, ind + 1)) {
                return true;
            }

            vis[i - 1][j] = '.';
        }

        if (i + 1 < n && word[ind] == board[i + 1][j] &&
            vis[i + 1][j] == '.') {

            vis[i + 1][j] = board[i + 1][j];

            if (solve(board, word, n, m, i + 1, j, vis, ind + 1)) {
                return true;
            }

            vis[i + 1][j] = '.';
        }

        if (j - 1 >= 0 && word[ind] == board[i][j - 1] &&
            vis[i][j - 1] == '.') {

            vis[i][j - 1] = board[i][j - 1];

            if (solve(board, word, n, m, i, j - 1, vis, ind + 1)) {
                return true;
            }

            vis[i][j - 1] = '.';
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size();

        vector<vector<char>> vis(n, vector<char>(m, '.'));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {

                    vis[i][j] = board[i][j];

                    if (solve(board, word, n, m, i, j, vis, 1)) {
                        return true;
                    }

                    vis[i][j] = '.';
                }
            }
        }

        return false;
    }
};