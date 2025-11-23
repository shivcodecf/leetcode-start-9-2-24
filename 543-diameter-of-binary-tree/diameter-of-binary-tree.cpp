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
        if (node == nullptr) {
            return 0;
        }

        int left =0,right =0;

        if(node->left)
        {
           left = 1 + solve(node->left);
        }

        if(node->right)
        {
           right = 1 + solve(node->right);
        }

        

         

        int x = left+right;

        ans = max(ans,x);

        return max(left,right);


    }

public:
    int diameterOfBinaryTree(TreeNode* root) { 
        solve(root); 
        return ans;
        }
};