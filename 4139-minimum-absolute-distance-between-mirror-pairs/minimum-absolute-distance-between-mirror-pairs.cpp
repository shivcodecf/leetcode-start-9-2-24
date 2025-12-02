class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        map<int, int> mp, mp1;

        int n = nums.size();

        // for (int i = n - 1; i >= 0; i--) {
        //     string s1 = to_string(nums[i]);
        //     int y = s1.size();
        //     mp[nums[i]] = i;
        //     mp1[nums[i]]++;
        // }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            string s = to_string(nums[i]);

            reverse(s.begin(), s.end());

            long long num = stoi(s);

            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, abs(i - mp[nums[i]]));
            }

            mp[num] = i;
        }

        return ans == INT_MAX ? -1 :ans;
    }
};