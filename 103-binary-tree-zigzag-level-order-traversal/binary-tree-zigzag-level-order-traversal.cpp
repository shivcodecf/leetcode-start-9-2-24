/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;

        if (!root) return {};

        q.push(root);

          

        int c = 0;

        vector<vector<int>> ans;

        while (!q.empty()) {

            int n = q.size();

            vector<int> v;

            c++;

            while (n--) {

                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (c % 2 == 0) {
                reverse(v.begin(), v.end());
            }

            ans.push_back(v);
        }

        return ans;
    }
};