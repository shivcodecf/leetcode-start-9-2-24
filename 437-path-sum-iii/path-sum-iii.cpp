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

     queue<TreeNode*>q;

     long long ans = 0;
     
     void solve(TreeNode* root,int target,long long sum)
     {      

         if(root == nullptr)
        {
            return;
        }

        sum+=root->val;

        if(sum == target)
        { 

            ans++;

          
           
        }

       

         

         solve(root->left,target,sum);

         solve(root->right,target,sum);

        

        

     }

public:
    int pathSum(TreeNode* root, int targetSum) {

       if(root==nullptr)
       {
        return 0;
       }

       q.push(root);

       while(!q.empty())
       {
         TreeNode* node = q.front();
         q.pop();
        
         solve(node,targetSum,0);

         if(node->left)
         {
            q.push(node->left);
         }
         if(node->right)
         {
            q.push(node->right);
         }
         
       }

        return ans;




    }
};