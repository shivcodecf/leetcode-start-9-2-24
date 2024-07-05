class Solution {
public:
    int dfs(int i, vector<int> &stones, int sum, vector<vector<int>> &dp){
        if(i == stones.size() || sum < 0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int a = stones[i] + dfs(i+1, stones, sum - stones[i], dp);
        int b = dfs(i+1, stones, sum, dp);
        int ans;
        if(abs(sum-a) < abs(sum-b)) ans = a;
        else ans = b;
        return dp[i][sum] = ans;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int temp = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(temp+1, -1));
        return abs(sum - 2*dfs(0, stones, temp, dp));
    }

};