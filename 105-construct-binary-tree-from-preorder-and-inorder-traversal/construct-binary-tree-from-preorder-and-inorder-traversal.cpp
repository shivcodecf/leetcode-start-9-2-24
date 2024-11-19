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

    int search(vector<int>& inorder, int start, int end, int curr)
    { 
        
        for(int i = start; i <= end; i++) {

            if(inorder[i] == curr) {

                return i;
                
            }

        }

        return -1;

    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx)
    {  
        int n = preorder.size();

        if (start > end || idx >= n) {
            return nullptr;
        }

        // Pick current element from preorder traversal
        int current = preorder[idx];
        idx++;  // Move to the next element in preorder traversal

        // Create a new node for the current value
        TreeNode* node = new TreeNode(current);

        // Find the index of this element in the inorder traversal
        int pos = search(inorder, start, end, current);

        // Recursively build the left and right subtrees
        node->left = solve(preorder, inorder, start, pos - 1, idx);
        
        node->right = solve(preorder, inorder, pos + 1, end, idx);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int idx = 0;  // Preorder index starts at 0

        int n = inorder.size();
        
        // Build the tree using the preorder and inorder traversal arrays

        return solve(preorder, inorder, 0, n - 1, idx);

    }
};
