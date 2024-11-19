class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;

        vector<long long> v(n);
        v[0] = nums[0];
        for (int i = 1; i < n; i++) {
            v[i] = v[i - 1] + nums[i];
        }

        map<long long, long long> mp;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        long long ans = 0;
        if (mp.size() == k) {
            ans = max(ans, (long long)v[k - 1]);
        }

        int j = 0;
        for (int i = k; i < n; i++) {

            mp[nums[i]]++;

            if (--mp[nums[j]] == 0) {

                mp.erase(nums[j]);
            }
            j++;

            if (mp.size() == k) {
                ans = max(ans, (long long)v[i] - v[j - 1]);
            }

        }

        return ans;
    }
};
