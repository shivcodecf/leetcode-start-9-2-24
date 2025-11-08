/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    int ans = 0;

    int solve(TreeNode* node) {

    
        int left = 0, right = 0;

        if (node->left) {
            left = 1 + solve(node->left);
        }

        if (node->right) {
            right = 1 + solve(node->right);
        }

        ans = max(ans, left + right);

        return max({left, right});

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        solve(root);

        return ans;
    }
};