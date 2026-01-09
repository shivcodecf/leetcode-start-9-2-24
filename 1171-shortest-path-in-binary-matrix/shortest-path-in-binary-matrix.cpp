class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // 8 directions
        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // min-heap: {distance, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        dist[0][0] = 1;
        pq.push({1, 0, 0});

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int d = cur[0];
            int r = cur[1];
            int c = cur[2];

            // reached destination
            if (r == n-1 && c == n-1) return d;

            // skip outdated paths
            // if (d > dist[r][c]) continue;

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0 &&
                    d + 1 < dist[nr][nc]) {

                    dist[nr][nc] = d + 1;
                    pq.push({d + 1, nr, nc});
                }
            }
        }

        return -1;
    }
};
