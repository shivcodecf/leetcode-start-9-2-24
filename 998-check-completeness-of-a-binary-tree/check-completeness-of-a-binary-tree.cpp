class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool nullFound = false; // Flag to detect if we've seen a null node

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                nullFound = true; // After this, all nodes must be null
            } else {
                if (nullFound) {
                    // If we see a non-null node after a null, the tree is not complete
                    return false;
                }
                // Add children to the queue
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true; // If no violations, the tree is complete
    }
};
