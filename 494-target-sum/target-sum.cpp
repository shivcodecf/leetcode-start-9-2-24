class Solution { 
   
   int solve(vector<int>& nums,int target,int ind,int ans)
   {  

    

      if(ind>=nums.size())
      {
        if(ans==target)
        {
            return 1;
        }
        return 0;
      }

        int t1=0,t2=0,t3=0;

     
        t1 = solve(nums,target,ind+1,ans-nums[ind])-nums[ind];
        t2 = solve(nums,target,ind+1,ans+nums[ind])+nums[ind];

        return t1+t2;
      
   }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int ans=0;
        
        return solve(nums,target,0,ans);

    }
};