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
   
   vector<int>ans;

   void solve(TreeNode* root)
   {
    if(root==nullptr)
    {
        return;
    }

    solve(root->left);

    ans.push_back(root->val);

    solve(root->right);

   }

public:
    bool isValidBST(TreeNode* root) {

        
        solve(root);

        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]<=ans[i-1])
            {
              return false;
            }
        }

        return true;
        
    }
};