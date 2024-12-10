class Solution {
    TreeNode* buildTree(vector<int>& v, int start, int end) {

        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(v[mid]);

        node->left = buildTree(v, start, mid - 1);
        node->right = buildTree(v, mid + 1, end);

        return node;
        
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        return buildTree(v, 0, v.size() - 1);
    }
};
