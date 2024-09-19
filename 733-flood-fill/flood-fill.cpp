class Solution {
public: 
    void dfs(int row, int col,vector<vector<int>>& image,vector<vector<int>>& ans,
    int color,int delRow[],int delCol[],int inColor){
        image[row][col] = color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
            image[nRow][nCol]==inColor && image[nRow][nCol]!=color){
                dfs(nRow,nCol,image,ans,color,delRow,delCol,inColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int iniColor = image[sr][sc];

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,image,ans,color,delRow,delCol,iniColor);
        return image;
    }
};