class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string path) {
        if (!root) return;

        // add current node
        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // if leaf → store path
        if (!root->left && !root->right) {
            ans.push_back(path);
            // return;
        }

        dfs(root->left, path);
        dfs(root->right, path);

    }

    vector<string> binaryTreePaths(TreeNode* root) {

        dfs(root, "");
        return ans;

    }
};
