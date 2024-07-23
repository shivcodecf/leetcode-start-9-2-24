#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int res = INT_MIN;

    int helper(vector<int>& height, int m) {
        
        stack<int> st;
        vector<int> left(m), right(m);

        // Initialize the stack with a boundary value
        st.push(-1);

        // Calculate left limits
        for (int i = 0; i < m; i++) {
            while (st.top() != -1 && height[i] <= height[st.top()]) {
                st.pop();
            }
            left[i] = st.top();
            st.push(i);
        }

        // Reinitialize the stack
        while (!st.empty()) st.pop();

        // Initialize the stack with a boundary value
        st.push(m);

        // Calculate right limits
        for (int i = m - 1; i >= 0; i--) {
            while (st.top() != m && height[i] <= height[st.top()]) {
                st.pop();
            }
            right[i] = st.top();
            st.push(i);
        }

        int ans = INT_MIN;

        // Calculate the maximal rectangle area using left and right limits
        for (int i = 0; i < m; i++) {
            ans = max(ans, height[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {


        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();

        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j] = height[j] + 1;
                } else {
                    height[j] = 0;
                }
            }

            res = max(helper(height, m), res);
        }





        return res;
    }
};
