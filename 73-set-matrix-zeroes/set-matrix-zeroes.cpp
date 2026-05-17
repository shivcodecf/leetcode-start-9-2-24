class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();

        set<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if(matrix[i][j]==0)
                st.insert({i, j});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (st.count({i, j})) {
                    int row = i;
                    int col = j;

                    for (int k = 0; k < n; k++) {
                        matrix[k][col] = 0;
                    }

                    for (int k = 0; k < m; k++) {
                        matrix[row][k] = 0;
                    }
                }
            }
        }
    }
};