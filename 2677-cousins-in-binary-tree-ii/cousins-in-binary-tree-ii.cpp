class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> levelSums;  // To store sum of values at each level

        // First pass: Calculate level sums
        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(levelSum);
        }

        // Second pass: Replace values
        q.push(root);
        root->val = 0;  // Set root value to 0
        int levelIndex = 1;

        while (!q.empty()) {
            int n = q.size();
            
            // Ensure levelIndex doesn't exceed levelSums size
            if (levelIndex >= levelSums.size()) break;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int siblingSum = 0;

                // Calculate the sibling sum for the current node
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                // Calculate the value for the children nodes, with bounds check
                int childValue = levelSums[levelIndex] - siblingSum;

                // Update left and right children values
                if (node->left) {
                    node->left->val = childValue;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = childValue;
                    q.push(node->right);
                }
            }

            levelIndex++;
        }

        return root;
    }
};
