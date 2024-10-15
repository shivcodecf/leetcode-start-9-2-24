/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
        
     void solve(TreeNode* root,TreeNode* node,vector<int>& v2)
     { 

       if(root==nullptr) return;

       v2.push_back(root->val);

       if(root->val==node->val)
       { 

        return;

       }

      if(root->val < node->val)
      {
        solve(root->right,node,v2);
      }
      else if(root->val > node->val)
      {
        solve(root->left,node,v2);
      }



     }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         
          vector<int>v,v1;

          solve(root,p,v);

          solve(root,q,v1);

           for(int i=0;i<v1.size();i++)
          {
            cout <<v1[i]<<" ";
          }

          cout <<endl;

            for(int i=0;i<v.size();i++)
          {
            cout <<v[i]<<" ";
          }
          int flag=0;

          for(int i=0;i<min(v.size(),v1.size());i++)
          {
            if(v[i]==v1[i])
            {
                continue;
            }
            else {
                flag=1;
                TreeNode* node = new TreeNode(v1[i-1]);
                 return node;
            }

          }

          if(flag==0)
          {
            if(v1.size()>=v.size())
            {
                  TreeNode* node = new TreeNode(v[v.size()-1]);
                   return node;
            }
            else {
                TreeNode* node = new TreeNode(v1[v1.size()-1]);
                 return node;
            }
           
          }
         

          TreeNode* node1 = new TreeNode(0);

          return node1;



    }
};