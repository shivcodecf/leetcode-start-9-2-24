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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<pair<TreeNode*,int>>q;

        if(root!=NULL)
        {
            q.push({root,1});
        }

        int c=0;

        

        while(!q.empty())
        {
            int n= q.size(),check=0;

            int c1=0;

            

            c++;

            vector<int>v;

            while(n--)
            {  
               TreeNode* temp = q.front().first;;

               int temp1 = q.front().second;
               q.pop();
               c1++;

               if(temp->val==x || temp->val == y)
               {
                check++;
                v.push_back(temp1);
               }


               if(temp->left!=NULL)
               {
                q.push({temp->left,c1});
               }
               

               

               if(temp->right!=NULL)
               {
                q.push({temp->right,c1});
               }
             

            }

            if(c>=3 && check==2)
            {   
                if(v[0]!=v[1])
                return true;
            }

        }

        return false;

        


    }
};