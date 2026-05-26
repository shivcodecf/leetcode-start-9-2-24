class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        int ans = nums[0], sum = nums[0];

        // [1,-2,0,3,-1]

        for (int i = 1; i < n; i++) {

            sum = max(nums[i], sum + nums[i]);

            ans = max(ans, sum);
        }

        int ans1 = nums[0], sum1 = nums[0];

        for (int i = 1; i < n; i++) {

            sum1 = min(nums[i], sum1 + nums[i]);

            ans1 = min(ans1, sum1);
        }


        return max(ans, abs(ans1));


    }
};