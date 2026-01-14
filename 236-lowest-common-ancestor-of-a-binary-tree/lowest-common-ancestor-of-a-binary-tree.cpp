class Solution {
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left  = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if (left && right) {
            return root;
        }

        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
