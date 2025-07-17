class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();

    int originalColor = image[sr][sc];
    if (originalColor == color) return image; // No need to fill if color is same

    queue<pair<int, int>> q;
    q.push({sr, sc});

    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

      

        for (auto [dx, dy] : dirs) {
            int newr = x + dx;
            int newc = y + dy;

            if (newr >= 0 && newr < n && newc >= 0 && newc < m && image[newr][newc] == originalColor) {
                q.push({newr, newc});
            }
        }

          image[x][y] = color;
    }

    return image;
}

};