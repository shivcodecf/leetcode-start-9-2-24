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

    int ans = INT_MIN;

    int solve(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int l = 0, r = 0;

        l = root->val + solve(root->left);

        r = root->val + solve(root->right);

        ans = max(ans,max(l+r-root->val,max(l,max(r,root->val))));

        return max(l, max(r,root->val));



    }

public:
    int maxPathSum(TreeNode* root) {

        solve(root);

        return ans;
    }
};