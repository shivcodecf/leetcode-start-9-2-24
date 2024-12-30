class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int length, int low, int high, int zero, int one, vector<int>& memo) {
        // Base Case: If the length exceeds the upper bound, no valid string
        if (length > high) return 0;

        // If already computed, return the stored result
        if (memo[length] != -1) return memo[length];

        // Count this string if its length is within bounds
        int count = (length >= low && length <= high) ? 1 : 0;

        // Recursive calls for extending the string with '0's and '1's
        count +=  solve(length + zero, low, high, zero, one, memo) % MOD;
        count += solve(length + one, low, high, zero, one, memo) % MOD;
        count = count%MOD;

        // Store the result in the memoization table
        return memo[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Memoization table: Initialize with -1 for states up to `high`
        vector<int> memo(high + 1, -1);

        // Start recursion from length 0
        return solve(0, low, high, zero, one, memo);
    }
};
