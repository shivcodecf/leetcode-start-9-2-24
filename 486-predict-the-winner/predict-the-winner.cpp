class Solution {
    private:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& memo) {
        if (i > j) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Player 1's choice: choose the leftmost or the rightmost element
        int chooseLeft = nums[i] - solve(i + 1, j, nums, memo);
        int chooseRight = nums[j] - solve(i, j - 1, nums, memo);
        
        // Maximize the score for Player 1
        memo[i][j] = max(chooseLeft, chooseRight);
        return memo[i][j];
    }
public:
    bool predictTheWinner(vector<int>& nums) {
          int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n - 1, nums, memo) >= 0;
    }
};