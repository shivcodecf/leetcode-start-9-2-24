class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {

            map<int, int> mp;

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                mp[nums[j]]++;

                if (mp.find(sum) != mp.end()) {
                    ans++;
                }
            }
        }

        return ans;
    }
};