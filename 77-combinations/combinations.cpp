class Solution {
    vector<vector<int>> result;  // Store the final combinations

    void solve(int n, int k, int start, vector<int>& current) {
        // If the current combination is of size k, add it to the result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Iterate over possible candidates starting from `start`
        for (int i = start; i <= n; ++i) {

            current.push_back(i);       // Include this element in the current combination
            solve(n, k, i + 1, current); // Recurse for the next element
            current.pop_back();         // Backtrack by removing the last added element
            
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;  // Temporary vector to store a combination
        solve(n, k, 1, current);  // Start from 1
        return result;  // Return the final combinations
    }
};
