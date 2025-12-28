class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {


       int n = mat.size();

       int m = mat[0].size();

       
       vector<vector<int>>v(n,vector<int>(m,INT_MAX));

       queue<pair<pair<int,int>,int>>q;
       


       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        { 
            

            if(mat[i][j]==0)
            {
                q.push({{i,j},0});
                v[i][j] = 0;
            }
        }
       }

       int dx[] = {0,1,0,-1};

       int dy[] = {1,0,-1,0};

       while(!q.empty())
       { 

        int x = q.front().first.first;

        int y = q.front().first.second;

        int dis = q.front().second;

        q.pop();



        for(int i=0;i<4;i++)
        {
            int newR = x+dx[i];
            int newC = y+dy[i];

            

            

            if(newR <n && newC <m && newR>=0 && newC>=0 && dis+1<v[newR][newC])
            {
                v[newR][newC] = dis+1;
                q.push({{newR,newC},dis+1});
            }




        }




       }


      return v;







        
    }
};