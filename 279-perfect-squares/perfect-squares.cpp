class Solution {
public:  

    int sum,check;

     int solve(int n, int current, std::vector<int>& memo) {

    if (current == n) {
        return 0;
    }
    if (current > n) {
        return INT_MAX;
    }
    if (memo[current] != -1) {
        return memo[current];
    }

    int minCount = INT_MAX;
    for (int i = 1; i * i <= n; ++i) {
        int res = solve(n, current + i * i, memo);
        if (res != INT_MAX) {
            minCount = min(minCount, res + 1);
        }
    }

    memo[current] = minCount;
    return minCount;

}

int numSquares(int n) {

    vector<int> memo(n + 1, -1);
    return solve(n, 0, memo);

}

};