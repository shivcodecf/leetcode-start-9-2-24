class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();

        vector<vector<int>>ans;

        int c=0;



        for(int i=0;i<m;i++)
        {
           int x = 0,y=i;
           vector<int>v;
           c++;

           while(x<n && y<m && x>=0 && y>=0)
           {
             v.push_back(mat[x][y]);
             x++;
             y--;
           }

           if(c%2)
           {
            reverse(v.begin(),v.end());
           }

           ans.push_back(v);

           cout <<c<<endl;


        }

        for(int i=1;i<n;i++)
        {
            int x = i,y=m-1;

            vector<int>v;

            c++;

            while(x<n && y<m && x>=0 && y>=0)
            {
              v.push_back(mat[x][y]);
              x++;
              y--;
            }

            if(c%2)
            {
                reverse(v.begin(),v.end());
            }

            ans.push_back(v);
        }

        vector<int>res;

        for(int i=0;i<ans.size();i++)
        {
          for(int j=0;j<ans[i].size();j++)
          {
            res.push_back(ans[i][j]);
          }
        }

        return res;

       

    }
};