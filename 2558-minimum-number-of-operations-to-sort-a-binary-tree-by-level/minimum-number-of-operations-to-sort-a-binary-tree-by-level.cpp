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
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;

        q.push(root);

        int ans=0;

        while(!q.empty())
        {
            int l = q.size();

            vector<int>v;

            while(l--)
            {
                TreeNode* x = q.front();
                v.push_back(x->val);
                q.pop();

                if(x->left!=nullptr)
                {
                    q.push(x->left);
                }
                if(x->right!=nullptr)
                {
                    q.push(x->right);
                }

            }

            map<int,int>mp;

            vector<int>v1;

            for(int i=0;i<v.size();i++)
            { 

                mp[v[i]] = i;

                v1.push_back(v[i]);

            }

            sort(v1.begin(),v1.end());

            for(int i=0;i<v.size();i++)
            {  
                int y = v[i];

                int z = mp[v1[i]];

               

                if(v[i]!=v1[i])
                {
                    swap(v[i],v[mp[v1[i]]]);

                    mp[y] = z;

                    mp[v1[i]] = i;

                    ans++;
                }
            }

            for(int i=0;i<v.size();i++)
            {
                cout <<v[i]<<" ";
            }
            cout <<endl;

        }

        return ans;


    }
};