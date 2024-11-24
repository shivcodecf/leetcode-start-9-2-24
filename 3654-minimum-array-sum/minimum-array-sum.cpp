int dp[101][101][101];

class Solution {
    int solve(int n, vector<int>& nums, int k, int op1, int op2, int ind) {
        if (ind >= n) {
            return 0; // Base case
        }

        if(dp[op1][op2][ind]!=-1)
        {
            return dp[op1][op2][ind];
        }

        int res = INT_MAX;

         int skip = nums[ind] + solve(n, nums, k, op1, op2, ind + 1);
        // res = min(res, nums[ind] + solve(n, nums, k, op1, op2, ind + 1));
        res = min(res,skip);

        // Option 1: Apply `op1` (divide by 2 and round up)
        if (op1 >= 1) {
            int newVal = (nums[ind] + 1) / 2;
            res = min(res, newVal + solve(n, nums, k, op1 - 1, op2, ind + 1));
        }

        // Option 2: Apply `op2` (subtract k)
        if (op2 >= 1 && nums[ind] >= k) {
            int newVal = nums[ind] - k;
            res = min(res, newVal + solve(n, nums, k, op1, op2 - 1, ind + 1));
        }

        // Option 3: Apply both `op1` and `op2` in both orders
        if (op1 >= 1 && op2 >= 1) {
            // Apply `op1` first, then `op2`
            int newVal1 = (nums[ind] + 1) / 2;
            if (newVal1 >= k) {
                newVal1 = newVal1 - k;
                res = min(res, newVal1 + solve(n, nums, k, op1 - 1, op2 - 1, ind + 1));
            }

            // Apply `op2` first, then `op1`
            if (nums[ind] >= k) {
                int newVal2 = nums[ind] - k;
                newVal2 = (newVal2 + 1) / 2;
                res = min(res, newVal2 + solve(n, nums, k, op1 - 1, op2 - 1, ind + 1));
            }
        }

        // Option 4: Skip current element

        // int skip = nums[ind] + solve(n, nums, k, op1, op2, ind + 1);
        // // res = min(res, nums[ind] + solve(n, nums, k, op1, op2, ind + 1));
        // res = min(res,skip);

        return dp[op1][op2][ind]= res;
    }

public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {

        memset(dp,-1,sizeof(dp));

        int n = nums.size();

        return solve(n, nums, k, op1, op2, 0);

    }
};
