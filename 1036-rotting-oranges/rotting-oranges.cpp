class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int countFreshOrange = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push({i, j});
                }
                if (visited[i][j] == 1) {
                    countFreshOrange++;
                }
            }
        }

        if (countFreshOrange == 0)
            return 0;
        if (q.empty())
            return -1;

        int minutes = -1;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {

            int s = q.size();

            while (s--) {
                auto [x, y] = q.front();

                q.pop();

                for (auto [dx, dy] : dirs) {
                    int newr = x + dx;
                    int newc = y + dy;

                    if (newr < m && newr >= 0 && newc < n && newc >= 0 &&
                        visited[newr][newc] == 1) {

                        countFreshOrange--;

                        visited[newr][newc] = 2;

                        q.push({newr, newc});
                    }
                }
            }

            minutes++;
        }

        if (countFreshOrange == 0)
            return minutes;
        return -1;
    }
};