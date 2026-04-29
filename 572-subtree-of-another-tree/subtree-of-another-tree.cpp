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

    bool solve(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr && subRoot == nullptr) {

            return true;
        }

        if ((root == nullptr && subRoot) || (root && subRoot == nullptr)) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        bool l = false, r = false;

        l = solve(root->left, subRoot->left);

        r = solve(root->right, subRoot->right);

        return l && r;



    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();

            if (x->val == subRoot->val) {
                bool check = solve(x, subRoot);

                if (check) {
                    return true;
                }
            }

            if (x->left) {
                q.push(x->left);
            }

            if (x->right) {
                q.push(x->right);
            }
        }

        return false;
    }
};