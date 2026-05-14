class Solution {

    bool solve(vector<vector<char>>& board, string& word, int ind, int i, int j,
               vector<vector<char>>& vis) {

        if (ind >= word.size()) {
            return true;
        }

        

        int n = board.size(), m = board[0].size();

        if (i + 1 < n && board[i + 1][j] == word[ind] && vis[i + 1][j] == '#') {
            vis[i + 1][j] = word[ind];
            if(solve(board, word, ind + 1, i + 1, j, vis)){
                return true;
            }
            vis[i + 1][j] = '#';
        }

        if (j + 1 < m && board[i][j + 1] == word[ind] && vis[i][j + 1] == '#') {
            vis[i][j + 1] = word[ind];
            if(solve(board, word, ind + 1, i, j + 1, vis)){
                return true;
            }
            vis[i][j + 1] = '#';
        }

        if (i - 1 >= 0 && board[i - 1][j] == word[ind] &&
            vis[i - 1][j] == '#') {
            vis[i - 1][j] = word[ind];
            if(solve(board, word, ind + 1, i - 1, j, vis)){
                return true;
            }
             vis[i-1][j] = '#';
        }

        if (j - 1 >= 0 && board[i][j - 1] == word[ind] &&
            vis[i][j - 1] == '#') {
            vis[i][j - 1] = word[ind];
            if(solve(board, word, ind + 1, i, j - 1, vis)){
                return true;
            }
            vis[i][j - 1] = '#';
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size();

        vector<vector<char>> vis(n, vector<char>(m, '#'));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = word[0];
                    if (solve(board, word, 1, i, j, vis)) {
                        return true;
                    }
                    vis[i][j] = '#';
                }
            }
        }

        return false;
    }
};