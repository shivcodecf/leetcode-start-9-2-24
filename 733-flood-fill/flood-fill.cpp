class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        queue<pair<int, int>> q;

        q.push({sr, sc});

        int value = image[sr][sc];

        if (value == color) return image;

        image[sr][sc] = color;

        int dx[] = {0, 1, 0, -1};

        int dy[] = {1, 0, -1, 0};

        int n = image.size();

        int m = image[0].size();

        while (!q.empty()) {    


            int x = q.front().first;

            int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int newR = x + dx[i];
                int newC = y + dy[i];

                if (newR < n && newC < m && newR>=0 && newC>=0) {

                    if (image[newR][newC] == value) {

                        image[newR][newC] = color;
                         q.push({newR, newC});
                        
                    }

                    

                   
                }
            }


        }


        return image;

    }
};