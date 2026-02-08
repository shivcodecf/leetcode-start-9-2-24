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

  vector<string>ans;
  
  void solve(TreeNode* root,string s)
  {
    if(root == nullptr)
    { 
        return;
    }

    s+=to_string(root->val);

    

    if(root->left == nullptr && root->right == nullptr)
    {
       ans.push_back(s);
    }

    s+="->";
     
   

    solve(root->left,s);

    solve(root->right,s);

  }

public:
    vector<string> binaryTreePaths(TreeNode* root) {

        solve(root,"");

        return ans;
        
    }
};