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
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        TreeNode* curr=root;
        if(prev!=NULL && prev->val>curr->val){
            if(first==NULL){
                //first abhi set nhi hua hai
                first=prev;
                second=curr;
            }else{
                //pehle se ek pair mila hua hai,toh second ko shift krdo
                second=curr;
            }

        }
        prev=curr;//prev ko aage badhao;
        
        inorder(root->right);

    }
};