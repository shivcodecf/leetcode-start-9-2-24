class Solution {
   
   void dfs(int i,int j,set<pair<int,int>>& st,set<pair<int,int>>& st1, vector<vector<int>>& vis,int m,int n)
   { 
     //up
     for(int start=i-1;start>=0;start--)
     {
        if(st.find({start,j})==st.end() && st1.find({start,j})==st1.end())
        {
            vis[start][j] = 1;
        }
        else {
            break;
        }
     }

     //down

      for(int start=i+1;start<m;start++)
     {
        if(st.find({start,j})==st.end() && st1.find({start,j})==st1.end())
        {
            vis[start][j] = 1;
        } else {
            break;
        }
     }

     // left

       for(int start=j-1;start>=0;start--)
     {
        if(st.find({i,start})==st.end() && st1.find({i,start})==st1.end())
        {
            vis[i][start] = 1;
        } else {
            break;
        }
     }

     // right

       for(int start=j+1;start<n;start++)
     {
        if(st.find({i,start})==st.end() && st1.find({i,start})==st1.end())
        {
            vis[i][start] = 1;
        } else {
            break;
        }
     }





   }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
      vector<vector<int>>vis(m,vector<int>(n,0));

      set<pair<int,int>>st,st1;

      for(int i=0;i<guards.size();i++)
      {
        st.insert({guards[i][0],guards[i][1]});
      }

       for(int i=0;i<walls.size();i++)
      {
        st1.insert({walls[i][0],walls[i][1]});
      }

      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(st.find({i,j})!=st.end())
            {
                dfs(i,j,st,st1,vis,m,n);
            }
        }
      }

      int ans=0;

      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(st.find({i,j})==st.end() && st1.find({i,j})==st1.end())
            {
                if(vis[i][j]==0)
                {
                    ans++;
                }
            }
        }
      }

      return ans;


    }
};