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
 vector<int> res;
    void inor(TreeNode* p)
    {
        if (!p) return;
        inor(p->left);
        res.push_back(p->val);
        inor(p->right);
    }
    bool isValidBST(TreeNode* root) {
        
          inor(root);
        
        for(int i=1;i<res.size();i++)
        {
            if(res[i]<=res[i-1])
            {
                return false;
            }
        }
        return true;

    }
};