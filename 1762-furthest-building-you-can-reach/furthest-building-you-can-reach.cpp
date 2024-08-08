class Solution {
  
//   int solve(vector<int>& heights,int bricks,int ladders,int ind,vector<vector<vector<int>>>& dp)
//   {     


//      int n=heights.size();

//      if(ind==n-1)
//      {
//         return ind;
//      }
    
//      if(ladders<=0 && ind+1<n && heights[ind+1]-heights[ind] > bricks)
//      {
//         return ind;
//      }

//      int take1= INT_MIN,take2=INT_MIN,take3=INT_MIN;

//      if(dp[bricks][ladders][ind]!=-1) return dp[bricks][ladders][ind];

//      if(heights[ind]-heights[ind+1]>=0)
//      {
//         take1= solve(heights,bricks,ladders,ind+1,dp);
//      }

//      if(heights[ind]-heights[ind+1]<0 && ladders>=1)
//      {
//         take2 = solve(heights,bricks,ladders-1,ind+1,dp);
        
//      }

//        if(heights[ind]-heights[ind+1]<0 && heights[ind+1]-heights[ind]<=bricks)
//        {
//          take3= solve(heights,bricks-(heights[ind+1]-heights[ind]),ladders,ind+1,dp);
//        }
    

//       return dp[bricks][ladders][ind] = max({take1,take2,take3});
        
     


//   }

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int n=heights.size(),ans=n-1,flag=0;
        priority_queue <int, vector<int>, greater<int>> q;

        for(int i=1;i<n;i++)
        {
           if(heights[i]-heights[i-1]<=0)
           {
             continue;
           }
           else {
              int x = heights[i]-heights[i-1];

              q.push(x);

              if(q.size()<=ladders && !flag)
              {  
                continue;
              }

            //   q.push(x);

              int y = q.top();
              flag=1;

              if(bricks>=y)
              {
                bricks-=y;
              }
              else {
                 ans = i-1;
                 break;
              }
              q.pop();

           }

        }

        return ans;









        
      
     
        

    





    }
};