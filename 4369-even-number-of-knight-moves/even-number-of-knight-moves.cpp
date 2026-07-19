class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> vis(8, vector<int>(8, -1));

        q.push({0, {start[0], start[1]}});

        // vis[start[0]][start[1]] = 1;

        // int dx[] = {}

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int count = it.first;

            int x = it.second.first;

            int y = it.second.second;

            vis[x][y] = 1;

            if (count % 2 == 0 && x == target[0] && y == target[1]) {
                return true;
            }

            int up = 0, down = 0, left = 0, right = 0;

            if ( y - 2 >= 0 && x + 1 < 8 && vis[x + 1][y - 2] == -1 ) {
                q.push({count + 1, {x + 1, y - 2}});
            }

            if ( y - 2 >= 0 && x - 1 >= 0 && vis[x - 1][y - 2] == -1) {
                q.push({count + 1, {x - 1, y - 2}});
            }

            if ( y - 1 >= 0 && x + 2 < 8 && vis[x + 2][y - 1] == -1) {
                q.push({count + 1, {x + 2, y - 1}});
            }

            if ( y + 1 < 8 && x + 2 < 8 && vis[x + 2][y + 1] == -1  ) {
                q.push({count + 1, {x + 2, y + 1}});
            }

            if (y + 2 < 8 && x + 1 < 8 && vis[x + 1][y + 2] == -1) {
                q.push({count + 1, {x + 1, y + 2}});
            }

            if (y + 2 < 8 && x - 1 >= 0 && vis[x - 1][y + 2] == -1) {
                q.push({count + 1, {x - 1, y + 2}});
            }

            if ( y + 1 < 8 && x - 2 >= 0 && vis[x - 2][y + 1] == -1) {
                q.push({count + 1, {x - 2, y + 1}});
            }

            if (y - 1 >= 0 && x - 2 >= 0 && vis[x - 2][y - 1] == -1) {
                q.push({count + 1, {x - 2, y - 1}});
            }
        }

        return false;
    }
};