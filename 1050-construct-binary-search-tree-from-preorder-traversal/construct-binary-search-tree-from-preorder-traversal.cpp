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
TreeNode* solve(vector<int>& preorder,int &max,int &min,int&i)
{
    if(i>=preorder.size())
    {
        return NULL;
    }
    TreeNode*root=nullptr;
    if(preorder[i]<max&&preorder[i]>min)
    {
        root= new TreeNode(preorder[i++]);
        root->left=solve(preorder,root->val,min,i);
        root->right=solve(preorder,max,root->val,i);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        return solve(preorder,max,min,i);
        
    }
};