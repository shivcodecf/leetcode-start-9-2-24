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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
     
     vector<vector<int>>ans;

     if(root==NULL) return ans;

     queue<TreeNode*>qu;

     qu.push(root);

     while(!qu.empty())
     {   

         vector<int>v;

         int n=qu.size();

          while(n--)
         {
            TreeNode *node = qu.front();
            qu.pop();
            if(node->left!=NULL) qu.push(node->left);
           if(node->right!=NULL) qu.push(node->right);
           v.push_back(node->val);

         }


         ans.push_back(v);


     }

     return ans;






    }
};