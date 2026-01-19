class Solution {
    unordered_set<int> del;
    vector<TreeNode*> forest;

    TreeNode* dfs(TreeNode* root, bool isRoot) {
        if (root == nullptr) return nullptr;

        bool deleted = del.count(root->val);

        if (isRoot && !deleted) {
            forest.push_back(root);
        }

        root->left  = dfs(root->left,  deleted);
        root->right = dfs(root->right, deleted);

        return deleted ? nullptr : root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int x : to_delete) del.insert(x);

        dfs(root, true);
        return forest;
    }
};
