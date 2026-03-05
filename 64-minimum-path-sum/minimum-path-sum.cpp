class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> q;

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));

        int dx[] = {1, 0};

        int dy[] = {0, 1};

        q.push({grid[0][0], {0, 0}});

        vis[0][0] = grid[0][0];

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int minSum = it.first;

            int x = it.second.first;

            int y = it.second.second;

            if (x == n - 1 && y == m - 1) {
                return minSum;
            }

            for (int i = 0; i < 2; i++) {
                int newX = x + dx[i];

                int newY = y + dy[i];

                if ( newX<n && newY<m && newX>=0 && newY>=0 &&  vis[x][y] + grid[newX][newY] < vis[newX][newY]) {
                    vis[newX][newY] = vis[x][y] + grid[newX][newY];

                    q.push({vis[newX][newY], {newX, newY}});
                }
            }
        }

        return -1;
    }
};