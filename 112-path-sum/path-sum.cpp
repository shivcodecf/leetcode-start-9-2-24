#include <bits/stdc++.h>
#define ll long long 
#define nl '\n'
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root ==NULL) return false;
        // Update the targetSum by subtracting the current node's value
        targetSum-=root->val;
           if (root->left == NULL && root->right == NULL) {
            // If it's a leaf, check if the updated targetSum is zero
            if(targetSum == 0){
                return true;
            }else{
                return false;
            }
        }

        // Recursively check the left and right subtree
        return (root->left && hasPathSum(root->left, targetSum)) ||
               (root->right && hasPathSum(root->right, targetSum));
    }
};