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

    int solve(TreeNode* root)
    {
        // if(root==nullptr) return 0;

        if(root->left==nullptr && root->right==nullptr) return 1;
          
          int x = INT_MAX,y=INT_MAX;
          if(root->left!=nullptr)
         x = 1+solve(root->left);
           if(root->right!=nullptr)
         y = 1+solve(root->right);

        return min(x,y);





    }

public:
    int minDepth(TreeNode* root) {

        if(root==nullptr) return 0;
        
        return  solve(root);


    }
};