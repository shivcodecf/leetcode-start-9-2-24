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
    int ans = 0;

    int solve(TreeNode* root)
    {
       if(root == nullptr)
       {
        return 2;
       }

       int r = solve(root->right);

       int l = solve(root->left);

       if(r==0 || l==0)
       { 

         ans++;
         return 1;

       }

       if(r==1 || l==1)
       {

        return 2;

       }
       

        return 0;

       

    }

public:
    int minCameraCover(TreeNode* root) {

        // 0 --> no camera , not being watched

        // 1--> camera , being watched

        // 2 --> no camera , being watched

       if(solve(root)==0)

       ans++;
      

       return ans;


    }
};