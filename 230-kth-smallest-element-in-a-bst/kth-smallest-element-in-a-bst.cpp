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
   
   void solve(TreeNode* root, vector<int>& v)
   {
    if(root==nullptr) return;

    v.push_back(root->val);

    solve(root->left,v);

    

    solve(root->right,v);
    
   }
    
public:
    int kthSmallest(TreeNode* root, int k) {
       vector<int>v;
       solve(root,v); 

       sort(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
       {
        cout <<v[i]<<" ";
       }
       return v[k-1];
    }
};