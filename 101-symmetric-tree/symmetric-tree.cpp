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

   bool solve(TreeNode* node1 , TreeNode* node2)
   {
    if(node1 == NULL  &&  node2 == NULL)
    {
        return true;
    }

    if(node1!=NULL  && node2 !=NULL)
    {
       bool a = solve(node1->left , node2->right);
       bool b = solve(node1->right , node2->left);

       if(a && b && node1->val == node2->val)
       {
        return true;
       }
       else {
        return false;
       }
    }
    else {
        return false;
    }

   }

public:
    bool isSymmetric(TreeNode* root) {
        
        return solve(root->left , root->right);

    }
};