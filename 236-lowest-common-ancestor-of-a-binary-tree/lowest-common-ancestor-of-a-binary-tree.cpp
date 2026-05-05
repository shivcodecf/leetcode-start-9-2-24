/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        // if(root->val == )

        TreeNode* l = solve(root->left, p, q);

        TreeNode* r = solve(root->right, p, q);

        if (r && l) {
            return root;
        } 

        return l?l :r;


        
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return solve(root, p, q);
    }
};