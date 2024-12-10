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

  
  void solve(TreeNode* root,vector<int>& v)
  {
    

    if(root==nullptr)
    {
        return;
    }

   v.push_back(root->val);

   solve(root->left,v);

   solve(root->right,v);


  }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        vector<int>v;
        solve(root,v);

        int n=queries.size(),m=v.size();

        vector<vector<int>>v1(n,vector<int>(2));

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            cout <<v[i]<<" ";
        }


        for(int i=0;i<n;i++)
        {
            int x = queries[i];

            int lower = lower_bound(v.begin(),v.end(),x)-v.begin();

            if(lower>=m)
            {
               v1[i][0] = v[m-1];
               v1[i][1] = -1;
            }
            else {
              if(v[lower]==x)
              {
                 v1[i][0] = v[lower];
                 v1[i][1] = v[lower];
              }
              else {
                 if(lower==0)
                 {
                    v1[i][0] = -1;
                    v1[i][1]= v[lower];
                 }
                 else {
                    v1[i][0] = v[lower-1];
                    v1[i][1] = v[lower];
                 }
                
              }
            }

          

        }

        return v1;

    }
};