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
     
     vector<pair<int,int>>v;

  

public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);

        int level = 0;

        while(!q.empty())
        {
            int n = q.size();

            int sum = 0;

            level++;

            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;

                if(node->left)
                {
                    q.push(node->left);
                }

                 if(node->right)
                {
                    q.push(node->right);
                }




            }

            v.push_back({sum,level});

        }

        sort(v.begin(),v.end());

        reverse(v.begin(),v.end());

        int ans = v[0].second;

        cout <<ans<<endl;

        for(int i=1;i<v.size();i++)
        {
           if(v[i].first==v[i-1].first)
           {
            ans = min(ans,v[i].second);
           }
           else {
            break;
           }
        }


       return ans;
        
    
    }
};