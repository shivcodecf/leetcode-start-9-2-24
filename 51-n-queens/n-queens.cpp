class Solution {
    vector<vector<string>> ans;

    bool isValid(int n, vector<string>& v, int row, int col) {

        for (int i = 0; i < n; i++) {

            if (v[row][i] == 'Q') {
                return false;
            }

            if (v[i][col] == 'Q') {
                return false;
            }
        }


        int row1 = row, col1 = col;

        while (row1 < n && row1 >= 0 && col1 < n && col1 >= 0) {
            if (v[row1][col1] == 'Q') {
                return false;
            }

            row1--;
            col1--;
        }

        row1 = row, col1 = col;

        while (row1 < n && row1 >= 0 && col1 < n && col1 >= 0) {
            if (v[row1][col1] == 'Q') {
                return false;
            }

            row1--;
            col1++;
        }

        return true;
    }
    void solve(int n, vector<string>& v, int row) {

        if (row >= n) {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (isValid(n, v, row, i)) {
                v[row][i] = 'Q';

                solve(n, v, row + 1);

                v[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> v(n, string(n, '.'));

        solve(n, v, 0);

        return ans;
    }
};