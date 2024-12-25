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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*>q;

        vector<int>ans;


        if(root==nullptr)
        {return ans;}

        q.push(root);

        
        
       

        while(!q.empty())
        {
            int l = q.size();

            int maxi =INT_MIN;

            while(l--)
            {
                TreeNode* x = q.front();
                q.pop();

                maxi = max(maxi,x->val);

                if(x->left!=nullptr)
                {
                 q.push(x->left);
                }
                if(x->right!=nullptr)
                {
                 q.push(x->right);
                }

            }

            ans.push_back(maxi);
        }

        return ans;

    }
};