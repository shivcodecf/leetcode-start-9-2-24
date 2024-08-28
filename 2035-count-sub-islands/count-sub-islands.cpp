class Solution {
public:
    bool island = true;

    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return true;
        }

        if (grid2[i][j] != 1) {
            return true;
        }

        if (grid2[i][j] != grid1[i][j]) {
            island = false;
        }

        grid2[i][j] = -1;
        // grid1[i][j] = 0;

        int a[] = {0, 0, 1, -1};
        int b[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int x = i + a[k];
            int y = j + b[k];

            if (x >= 0 && y >= 0 && x < n && y < m) {
                dfs(x, y, grid1, grid2, n, m);
            }
        }

        return island;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid2.size();
        int m = grid2[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                    island = true;
                    if (dfs(i, j, grid1, grid2, n, m)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
