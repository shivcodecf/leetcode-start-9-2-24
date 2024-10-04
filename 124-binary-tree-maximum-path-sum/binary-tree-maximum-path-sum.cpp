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

int maxSum;

int solve(TreeNode* root){

    if(root == NULL) return 0;

    int left = solve(root->left);

    int right = solve(root->right);

    int n_accha = max(left,right) + root->val;

    int sab_acche = root->val + left + right;

    int root_accha = root->val;

    maxSum = max({n_accha, sab_acche,root_accha,maxSum});


    return max(root_accha,n_accha);



    

   
}

    int maxPathSum(TreeNode* root) {


        maxSum = INT_MIN;

        solve(root);

        return  maxSum;


    }
};