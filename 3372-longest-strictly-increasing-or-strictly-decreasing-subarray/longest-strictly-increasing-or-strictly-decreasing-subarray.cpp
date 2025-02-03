class Solution {


    int solve(vector<int>& nums,int ind,int prev)
    {
        if(ind>=nums.size())
        {
            return 0;
        }

        int take = INT_MIN,notake=INT_MIN;

        

        if(nums[ind]>prev)
        {
          take = 1+solve(nums,ind+1,nums[ind]);
        }

        notake = solve(nums,ind+1,prev);

        return max({take,notake});



    }

    int solve1(vector<int>& nums,int ind,int prev)
    {
        if(ind<0)
        {
            return 0;
        }

        int take = INT_MIN,notake=INT_MIN;

       

        if(nums[ind]>prev)
        {

          take = 1 + solve(nums,ind-1,nums[ind]);

        }

         notake = solve(nums,ind-1,prev);

         return max({take,notake});

    }

public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n=nums.size();

        int prev = nums[0],c=1,ans=INT_MIN;

        for(int i=1;i<n;i++)
        {
          if(nums[i]>prev)
          {
            c++;
            prev = nums[i];
          }
          else {
            ans = max(ans,c);
            c = 1;
            prev = nums[i];

          }
        }

         ans = max(ans,c);

        prev = nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
          if(nums[i]>prev)
          {
            c++;
            prev = nums[i];
          }
          else {
            ans = max(ans,c);
            c = 1;
            prev = nums[i];

          }
        }

         ans = max(ans,c);

        return ans;


        
        
       

    }
};