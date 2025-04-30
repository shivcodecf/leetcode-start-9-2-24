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
        
     vector<vector<int>>v;

     queue<TreeNode*>q;

     if(root!=NULL)

     q.push(root);

     while(!q.empty())
     {
        int n= q.size();

        vector<int>v1;

        while(n--)
        {
            TreeNode* temp = q.front();
            q.pop();

            v1.push_back(temp->val);

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);

            }




        }

        v.push_back(v1);

     }

     return v;

     


    }
};