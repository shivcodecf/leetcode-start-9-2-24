/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = INT_MIN;

    int solve(TreeNode* node) {
        if (!node) return 0;

        // Compute max contribution from left and right subtrees
        int left = max(0, solve(node->left));
        int right = max(0, solve(node->right));

        // Path that goes through the current node (could be the answer)
        ans = max(ans, node->val + left + right);

        // Return best path that can be extended upwards
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
