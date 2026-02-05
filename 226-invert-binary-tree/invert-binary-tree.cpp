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
    
    TreeNode* solve(TreeNode* root)
    {
        
       
       if(root == nullptr)
       {
        return nullptr;
       }

       TreeNode* temp = root->left;

       root->left = solve(root->right);

       root->right = solve(temp);

       return root;

        
    }

public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) return nullptr;
        
        solve(root);

        return root;


    }
};