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
    
    TreeNode* solve(TreeNode* root , TreeNode* p , TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode*left = solve(root->left,p,q);
        TreeNode*right = solve(root->right,p,q);

        if(left && right)
        {
            return root;
        }
        //   else if((root == p && left) || (root == p && right) || (root == q && right) || (root == q && left))
        // {
        //     return root;
        // }
        else if(left)
        {
            return left;
        }
        else if(right)
        {
            return right;
        }
          
        return nullptr;
        
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return solve(root,p,q);
        
    }
};