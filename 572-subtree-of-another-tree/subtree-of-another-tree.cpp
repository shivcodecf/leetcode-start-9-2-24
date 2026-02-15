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

    bool solve(TreeNode*node, TreeNode*subRoot) {

        if(node == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if(node==nullptr || subRoot == nullptr)
        {
            return false;
        }

        // if (node->left == nullptr && node->right == nullptr &&
        //     subRoot->left == nullptr && subRoot->right == nullptr) {

        //      if(node->val == subRoot->val)
        //      {
        //         return true;
        //      }   

        //     return false;

        // }

        if (node->val != subRoot->val) {
            return false;
        }

        bool left = solve(node->left, subRoot->left);

        bool right = solve(node->right, subRoot->right);

        return left && right;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == subRoot->val) {
                if (solve(node, subRoot)) {
                    return true;
                }
            }
            if(node->left)
            {
                q.push(node->left);
            }
             if(node->right)
            {
                q.push(node->right);
            }
        }

        return false;
    }
};