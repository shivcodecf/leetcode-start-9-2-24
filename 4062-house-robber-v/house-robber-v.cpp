class Solution {

     long long dp[100001];

    long long solve(vector<int>& nums, vector<int>& colors, int ind) {
        int n = nums.size();

        // if(ind == n-1)
        // {
        //     return nums[ind];
        // }

        if (ind >= n) {
            return 0;
        }

           if (dp[ind] != -1) {
            return dp[ind];
        }

        if(ind==n-1)
        {
            return nums[ind];
        }

        long long take = 0, notake = 0, adjTake = 0;

     

        notake = solve(nums, colors, ind + 1);

        int nextIdx = -1;

        if (colors[ind] == colors[ind + 1]) {

            nextIdx = ind+2;

        }
        else {
            nextIdx = ind+1;
        }

        take = nums[ind] +  solve(nums, colors,  nextIdx);


        return dp[ind] = max(take, notake);
    }

public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        memset(dp,-1,sizeof(dp));

        return solve(nums, colors, 0);
    }
};