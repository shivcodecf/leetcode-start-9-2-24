class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0, ans = 0;

        mp[0] = 1; // Edge case for when prefixSum itself is k

        for (int num : nums) {
            
            prefixSum += num;
            int check = prefixSum - k;

            if (mp.find(check) != mp.end()) {
                ans += mp[check]; // Add all previous occurrences
            }

            mp[prefixSum]++; // Store the frequency of prefixSum
        }

        return ans;
    }
};
