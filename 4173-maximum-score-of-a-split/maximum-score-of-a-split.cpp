class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size();

        vector<long long>pref(n,0);

        vector<long long>Min(n);

        pref[0] = nums[0];

        for(int i=1;i<n;i++)
        {
           pref[i] = pref[i-1] + nums[i];
        }

        long long mini = nums[n-1];

        Min[n-1] = mini;

        

        for(int i=n-2;i>=0;i--)
        {
          mini = min(mini,(long long)nums[i]);
          Min[i] = mini;
        }

        long long ans = INT_MIN;

        for(int i=0;i<n-1;i++)
        {
            ans = max(ans,pref[i]-Min[i+1]);
        }

        return ans;


        
    }
};