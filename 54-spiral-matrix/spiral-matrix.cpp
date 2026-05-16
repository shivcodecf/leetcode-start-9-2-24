class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();

        map<pair<int, int>, int> mp;

        int i = 0, j = 0;
        int dir = 1;   // 1 = right, 2 = down, 3 = left, 4 = up

        vector<int> ans;

        while (true) {

            // Correct boundary check:
            // i >= 0 and j >= 0 are also required.
            if (i >= 0 && i < n && j >= 0 && j < m &&
                mp.find({i, j}) == mp.end()) {

                ans.push_back(matrix[i][j]);
                mp[{i, j}]++;

                if (dir == 1) {               // right
                    j++;
                    if (j >= m || mp.find({i, j}) != mp.end()) {
                        dir = 2;
                        j--;
                        i++;
                    }
                }
                else if (dir == 2) {          // down
                    i++;
                    if (i >= n || mp.find({i, j}) != mp.end()) {
                        dir = 3;
                        i--;
                        j--;
                    }
                }
                else if (dir == 3) {          // left
                    j--;
                    if (j < 0 || mp.find({i, j}) != mp.end()) {
                        dir = 4;
                        j++;
                        i--;
                    }
                }
                else {                        // up
                    i--;
                    if (i < 0 || mp.find({i, j}) != mp.end()) {
                        dir = 1;
                        i++;
                        j++;
                    }
                }
            }
            else {
                break;
            }
        }

        return ans;
    }
};