int dp[10001];

class Solution {

    int solve(vector<int>& nums,int ind)
    {  

        int n=nums.size();

        if(ind>=n) return INT_MAX;

        if(ind==n-1)  return 0;

        long long ans = INT_MAX;

        if(dp[ind]!=-1) return dp[ind];

        for(int i=1;i<=nums[ind];i++)
        {
            ans = min((long long)ans,1+(long long)solve(nums,ind+i));
        }

        return dp[ind] = ans;


    }

public:
    int jump(vector<int>& nums) {
        
         int n=nums.size();

         memset(dp,-1,sizeof(dp));

         return solve(nums,0);

    }
};