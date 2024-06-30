class Solution {
public:  
    int solve(vector<int>& A, int n, int ind, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }

        int take = solve(A, n, ind + 2, dp) + A[ind];
        int notake = solve(A, n, ind + 1, dp);

        return dp[ind] = max(take, notake);
    }

    int rob(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        if (n == 1) return A[0];
        if (n == 2) return max(A[0], A[1]);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Rob houses from 0 to n-2
        int rob1 = solve(A, n - 1, 0, dp1);
        // Rob houses from 1 to n-1
        int rob2 = solve(A, n, 1, dp2);

        return max(rob1, rob2);
    }
};
