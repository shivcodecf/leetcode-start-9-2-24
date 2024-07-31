class Solution {
  
int width;
 private:

 int solve(vector<vector<int>>& books,int ind,int rem_width,int maxH,vector<vector<int>>& dp)
 { 

    if(ind>=books.size()) return maxH;
    if(dp[ind][rem_width]!=INT_MAX) return dp[ind][rem_width];

    int height = books[ind][1];
    int w = books[ind][0];
    int skip =INT_MAX , take = INT_MAX;

    if(w<=rem_width)
    {
        take =  solve(books,ind+1,rem_width-w,max(maxH,height),dp);
    }

    skip = maxH + solve(books,ind+1,width-w,height,dp);

    return dp[ind][rem_width] = min(take,skip);
    
    
    





 }


public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        width = shelfWidth;

        vector<vector<int>>dp(1001,vector<int>(1001,INT_MAX));
     
        return solve(books,0,width,0,dp);


    }
};