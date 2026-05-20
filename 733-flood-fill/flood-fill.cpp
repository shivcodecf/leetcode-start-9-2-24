class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        queue<pair<int,int>>q;

        q.push({sr,sc});

        int n = image.size();

        int m = image[0].size();
         
        int dx[] = {0,+1,0,-1};

        int dy[] = {-1,0,+1,0};

        int initialColor = image[sr][sc];

        while(!q.empty()){

         int x = q.front().first;
         int y = q.front().second;

         image[x][y] = color;

         q.pop();

         for(int i=0;i<4;i++)
         {
            int newX = x + dx[i];

            int newY = y + dy[i];

            if(newX>=0 && newX<n && newY>=0 && newY<m && image[newX][newY]==initialColor && image[newX][newY]!=color){
               
                q.push({newX,newY});

            }
         }


        }

        return image;
        
    }
};