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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*>q;

        vector<vector<int>>ans;

        if(root==nullptr) return ans;

        q.push(root);

       

    

        while(!q.empty())
        {   
            int n= q.size();

             vector<int>v1;

            while(n--)
            { 

                TreeNode* node = q.front();
                q.pop();

            if(node->left!=nullptr) q.push(node->left);

            if(node->right!=nullptr) q.push(node->right);

            v1.push_back(node->val);

            }

            ans.push_back(v1);
          

        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};