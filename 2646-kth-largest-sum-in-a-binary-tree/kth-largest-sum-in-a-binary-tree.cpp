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
    long long kthLargestLevelSum(TreeNode* root, int k) {

    if (!root) return 0; // Edge case: empty tree
        
     queue<TreeNode*> q;

       

      q.push(root);

     

      vector<long long>ans;

      while(!q.empty())
      { 

        long long x=q.size();

        long long res =0;

        while(x--)
        {
            TreeNode* node = q.front();
            q.pop();

            long long x = node->val;

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);

            res+=x;

            




        }

        ans.push_back(res);


      }


      sort(ans.begin(),ans.end());

       reverse(ans.begin(),ans.end());

       if(ans.size()<k) return -1;

       return ans[k-1];

     

    }
};