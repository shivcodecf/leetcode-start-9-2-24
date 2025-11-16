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
      
      TreeNode* solve(TreeNode* node , int val)
      {

        if(node == nullptr)
        {
          TreeNode* node1 = new TreeNode(val);

          return node1;
        }

        if(node->val<val)
        {

         node->right = solve(node->right,val);

        }
        else if(node->val > val)
        {
            node->left  = solve(node->left,val);
        }

        return node;
        


      }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
       return solve(root,val);

        
    }
};