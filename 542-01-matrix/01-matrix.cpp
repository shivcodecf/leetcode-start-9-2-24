class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    dis[i][j] = 0;
                }
            }
        }

        int dx[] = {0, +1, 0, -1};

        int dy[] = {-1, 0, +1, 0};

        // int path,x,y;

        while (!q.empty()) {

            auto it = q.front();

            q.pop();

            int path = it.first;

            int x = it.second.first;

            int y = it.second.second;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    path + 1 < dis[newX][newY]) {
                    dis[newX][newY] = path + 1;
                    q.push({path + 1, {newX, newY}});
                }
            }
        }

        return dis;
    }
};