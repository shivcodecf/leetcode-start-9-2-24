class Solution {
    unordered_map<TreeNode*, vector<int>> dp;

    int solve(TreeNode* root, int check) {
        if (root == nullptr) return 0;

        // If already computed, return it
        if (dp.count(root) && dp[root][check] != -1)
            return dp[root][check];

        if (!dp.count(root))
            dp[root] = vector<int>(2, -1);

        int ans1 = 0, ans2 = 0;

        if (check == 0) {
            int a = solve(root->left, 1);
            int b = solve(root->right, 1);
            ans1 = root->val + a + b;
        }

        ans2 = solve(root->left, 0) + solve(root->right, 0);

        return dp[root][check] = max(ans1, ans2);
    }

public:
    int rob(TreeNode* root) {
        return solve(root, 0);
    }
};
