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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*>q;

        if(root!=NULL)
        {
            q.push(root);
        }

        vector<int>ans;

        while(!q.empty())
        {
            int n = q.size();
            int c=0;

             vector<int>v1;

            while(n--)
            { 
                
                c++;
                TreeNode* temp = q.front();

                q.pop();

              

                v1.push_back(temp->val);

                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                 if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }

                


            }

            ans.push_back(v1[v1.size()-1]);
        }

        return ans;

    }
};