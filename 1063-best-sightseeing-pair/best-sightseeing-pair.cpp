class Solution {
    int solve(vector<int>& values, int i, int max_i, vector<int>& memo) {
        // Base case: If we reach the last index, there's no pair to form
        if (i >= values.size()) {
            return 0;
        }

        // If the result for this index is already computed, return it
        if (memo[i] != -1) {
            return memo[i];
        }

        // Calculate the score for the current pair (max_i + values[i] - i)
        int current_score = max_i + values[i] - i;

        // Update max_i for the next recursive call
        max_i = max(max_i, values[i] + i);

        // Recursively calculate the best score starting from the next index
        int next_score = solve(values, i + 1, max_i, memo);

        // Store the maximum score in the memo table
        return memo[i] = max(current_score, next_score);
    }

public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> memo(n, -1); // Initialize memoization table
        return solve(values, 1, values[0], memo);
    }
};
