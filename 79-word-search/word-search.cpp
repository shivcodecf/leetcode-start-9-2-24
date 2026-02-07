class Solution {

    bool solve(vector<vector<char>>& board, string& word, string& s, int i,
               int j, int pointer, vector<vector<int>>& vis) {
        int n = board.size(), m = board[0].size();

        int len = word.size();

        vis[i][j] = 1;

        s += board[i][j];

        if (pointer == len - 1) {
            bool ok = (s == word);
            vis[i][j] = -1;
            s.pop_back();
            return ok;
        }

        bool l = false, r = false, t = false, b = false;

        if (i - 1 < n && j < m && i - 1 >= 0 && j >= 0 && vis[i - 1][j] == -1 &&
            board[i - 1][j] == word[pointer + 1]) {

            l = solve(board, word, s, i - 1, j, pointer + 1, vis);
        }

        if (i + 1 < n && j < m && i + 1 >= 0 && j >= 0 && vis[i + 1][j] == -1 &&
            board[i + 1][j] == word[pointer + 1]) {
            r = solve(board, word, s, i + 1, j, pointer + 1, vis);
        }

        if (i < n && j + 1 < m && i >= 0 && j + 1 >= 0 && vis[i][j + 1] == -1 &&
            board[i][j + 1] == word[pointer + 1]) {

            t = solve(board, word, s, i, j + 1, pointer + 1, vis);
        }

        if (i < n && j - 1 < m && i >= 0 && j - 1 >= 0 && vis[i][j - 1] == -1 &&
            board[i][j - 1] == word[pointer + 1]) {

            b = solve(board, word, s, i, j - 1, pointer + 1, vis);
        }

        vis[i][j] = -1;

        if (s.size()) {
            s.pop_back();
        }

        return l | r | t | b;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));

        string s = "";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {

                    if (solve(board, word, s, i, j, 0, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};