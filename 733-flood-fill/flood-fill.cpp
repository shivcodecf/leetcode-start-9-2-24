class Solution {
    private:

    void dfs(vector<vector<int>>& image,int x,int y,int color,int source)
    {
      
        int n=image.size(),m=image[0].size();

          if(x <0 || x >=n || y<0 || y>=m )
          {
            return;
          }
           if(image[x][y]!=source)
          {
            return;
          }

        
        image[x][y] = color;


       int drow [] = {-1,0,+1,0};

       int dcol [] = {0,+1,0,-1};

       for(int i=0;i<4;i++)
       { 

        int nrow = drow[i] + x;
        int ncol = dcol[i] + y;

      
        
            dfs(image,nrow,ncol,color,source);
        


       }



    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

                   int n=image.size(),m=image[0].size();

                    if(color==image[sr][sc]){
            return image;
        }
        
                   int source = image[sr][sc];
       
              
                   dfs(image,sr,sc,color,source);
       

                    return image;



    }
};