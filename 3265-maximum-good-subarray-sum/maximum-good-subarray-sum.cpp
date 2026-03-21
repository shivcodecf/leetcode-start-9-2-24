class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> pref(n);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        unordered_map<int, long long> mp; // value → min prefix sum

        long long ans = LLONG_MIN;
        bool found = false;

        for (int i = 0; i < n; i++) {

            long long req1 = nums[i] - k;
            long long req2 = nums[i] + k;

            if (mp.count(req1)) {
                long long sum = pref[i] - mp[req1];
                ans = max(ans, sum);
                found = true;
            }

            if (mp.count(req2)) {
                long long sum = pref[i] - mp[req2];
                ans = max(ans, sum);
                found = true;
            }

            long long prevPref = (i > 0) ? pref[i - 1] : 0;

            if (mp.count(nums[i])) {
                mp[nums[i]] = min(mp[nums[i]], prevPref);
            } else {
                mp[nums[i]] = prevPref;
            }
        }

        return found ? ans : 0;
    }
};