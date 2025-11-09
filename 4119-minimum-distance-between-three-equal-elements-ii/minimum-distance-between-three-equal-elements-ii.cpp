class Solution {
public:
    int minimumDistance(vector<int>& nums) {


          vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }

        unordered_map<int, int> mp;

        for (int i = 0; i < v.size(); i++) {
            mp[nums[i]]++;
        }

        int ans = INT_MAX;

        int n = v.size();

        for (int i = 0; i < v.size(); i++) {

            int sum = 0;

            if (mp[v[i].first] >= 3 && i + 2 < n) {
                sum = abs(v[i].second - v[i + 1].second) +
                      abs(v[i + 1].second - v[i + 2].second) +
                      abs(v[i].second - v[i + 2].second);

                ans = min(ans, sum);
                mp[v[i].first]--;
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};