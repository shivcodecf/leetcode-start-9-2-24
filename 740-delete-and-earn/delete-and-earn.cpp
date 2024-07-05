class Solution {
    int N = 1e4+1;
public:
    int f(int i,vector<int> &nums,vector<int> &freq,vector<int> &dp){

       if(i>=N)
       return 0;

       if(dp[i] != -1)
       return dp[i];

       int p,np;
       p = freq[i]*i + f(i+2,nums,freq,dp);
       np = f(i+1,nums,freq,dp);

        return dp[i] = max(p,np);

    }
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> freq(N,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        vector<int> dp(N,-1);

        return f(1,nums,freq,dp);
    
    }
};