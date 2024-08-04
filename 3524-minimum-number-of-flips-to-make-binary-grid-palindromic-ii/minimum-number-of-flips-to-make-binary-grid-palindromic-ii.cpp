class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {

       int n=grid.size(),m=grid[0].size();

       int ans=0;

       for(int i=0;i<n/2;i++)
       {
        for(int j=0;j<m/2;j++)
        {
           int x = grid[i][j];
           x+=grid[n-1-i][j];
           x+=grid[n-1-i][m-1-j];
           x+=grid[i][m-1-j];

           ans+=min(x,4-x);

        }
       }
       int cnt=0,c=0;

       if(n%2)
       {
        for(int i=0;i<m/2;i++)
        {
            if(grid[n/2][i]!=grid[n/2][m-1-i])
            {
                ans++;
                cnt++;
            }
            if(grid[n/2][i]==grid[n/2][m-1-i] && grid[n/2][i]==1)
            {
               c++;
            }
        }
       }
       if(m%2)
       {
        for(int i=0;i<n/2;i++)
        {
            if(grid[i][m/2]!=grid[n-1-i][m/2])
            {
                ans++;
                cnt++;
            }
            
            if(grid[i][m/2]==grid[n-1-i][m/2] && grid[i][m/2]==1)
            {
                c++;
            }
        }
       }

       if(c%2==1 && cnt==0) ans+=2;

       if(grid[n/2][m/2]==1 && n%2==1 && m%2==1) ans++;

       return ans;



    }
};