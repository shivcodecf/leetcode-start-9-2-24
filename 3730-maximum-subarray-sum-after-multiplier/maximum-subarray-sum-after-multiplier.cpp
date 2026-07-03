class Solution {
public:
    long long solve(vector<int>& nums, int k, bool multiply) {
        int n = nums.size();
        const long long NEG = -4e18;

        long long dp0 = nums[0];
        long long op = multiply ? 1LL * nums[0] * k : nums[0] / k;
        long long dp1 = op;
        long long dp2 = NEG;

        long long ans = max(dp0, dp1);

        for (int i = 1; i < n; i++) {
            long long val = nums[i];
            long long operated = multiply ? val * k : nums[i] / k;

            long long new_dp0 = max(val, dp0 + val);

            long long new_dp1 = max({
                operated,
                dp0 + operated,
                dp1 + operated
            });

            long long new_dp2 = max({
                val,
                dp1 + val,
                dp2 + val
            });

            dp0 = new_dp0;
            dp1 = new_dp1;
            dp2 = new_dp2;

            ans = max({ans, dp0, dp1, dp2});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        long long multiplyAns = solve(nums, k, true);
        long long divideAns = solve(nums, k, false);
        return max(multiplyAns, divideAns);
    }
};