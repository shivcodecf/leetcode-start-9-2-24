class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();

        int dir = 1;

        int i = 0, j = 0;

        set<pair<int, int>> st;

        vector<int> ans;

        // st.insert({i,j});

        // ans.push_back(matrix[0][0]);

        while (i < n && j < m) {

            // if(st.count({i,j}))
            // {
            //     break;
            // }

            if (!st.count({i, j}) && i<n && j<m && i>=0 && j>=0) {

                if (dir == 1) {

                    ans.push_back(matrix[i][j]);

                    st.insert({i, j});

                    j++;

                    if (j >= m || st.count({i, j})) {
                        j--;
                        i++;
                        dir++;
                    }


                } else if (dir == 2) {

                    st.insert({i, j});

                    ans.push_back(matrix[i][j]);

                    i++;

                    if (i >= n || st.count({i, j})) {
                        i--;
                        j--;
                        dir++;
                    }

                }

                else if (dir == 3) {

                    st.insert({i, j});

                    ans.push_back(matrix[i][j]);

                    j--;

                    if (j < 0 || st.count({i, j})) {
                        j++;
                        i--;
                        dir++;
                    }

                }

                else if (dir == 4) {

                    st.insert({i, j});

                    ans.push_back(matrix[i][j]);

                    i--;

                    if (i < 0 || st.count({i, j})) {
                        i++;
                        j++;
                        dir = 1;
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