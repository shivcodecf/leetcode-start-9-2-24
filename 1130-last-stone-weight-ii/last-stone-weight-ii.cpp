class Solution {
private:
int solve(vector<int>& stones,int idx,int value,vector<vector<int>>& dp){
    //base case
    if(idx==stones.size()){
        if(value<0)return 1e9;
        return 0;
    }
    // value can be -3000 to +3000 that is why [value + 3000] 
    if(dp[idx][value+3000]!=-1)return dp[idx][value+3000];
    //condition
    int ans1 = stones[idx] + solve(stones,idx+1,value+stones[idx],dp);
    int ans2 = -stones[idx] + solve(stones,idx+1,value-stones[idx],dp);
    return dp[idx][value+3000] = min(ans1,ans2);
}
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> dp(stones.size()+1,vector<int>(6000,-1));
        return solve(stones,0,0,dp);
    }
};