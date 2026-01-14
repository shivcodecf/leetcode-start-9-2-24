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
    
    bool solve(TreeNode* node , int target)
    { 

      if(node==nullptr)
      {
        return 0;
      }

       target-=node->val;

      if(node->left==nullptr && node->right==nullptr)
      {
        return target == 0;
      }

      return solve(node->left,target) || solve(node->right,target);




    }


public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root,targetSum);
        
    }
};